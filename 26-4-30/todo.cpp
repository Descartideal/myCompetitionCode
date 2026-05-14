#include <bits/stdc++.h>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

struct Task {
    int id = 0;
    bool done = false;
    string content;
    string created_at;
    string updated_at;
    string due_at;
    string done_at;
};

struct Msg {
    string role;
    string content;
};

const string TODO_FILE = "todo.json";
const string MEMORY_FILE = "memory.txt";
const string API_URL = "https://api.deepseek.com/chat/completions";
const string MODEL = "deepseek-chat";

const string RESET = "\033[0m";
const string BLUE  = "\033[34m";
const string GREEN = "\033[32m";
const string RED   = "\033[31m";

void init_console() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;
    if (GetConsoleMode(hOut, &mode)) {
        mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, mode);
    }
#endif
}

void sys_out(const string& s) {
    cout << GREEN << s << RESET;
}

void ai_out(const string& s) {
    if (!s.empty()) {
        cout << BLUE << s << RESET << '\n';
    }
}

void err_out(const string& s) {
    cerr << RED << s << RESET << '\n';
}

string trim(const string& s) {
    size_t l = 0, r = s.size();
    while (l < r && isspace((unsigned char)s[l])) l++;
    while (r > l && isspace((unsigned char)s[r - 1])) r--;
    return s.substr(l, r - l);
}

bool contains_any(const string& s, initializer_list<string> keys) {
    for (const auto& k : keys) {
        if (s.find(k) != string::npos) return true;
    }
    return false;
}

bool wants_exit_phrase(const string& s) {
    if (contains_any(s, {"不要退出", "别退出", "先别退出", "不能退出"})) return false;

    return contains_any(s, {
        "退出程序",
        "关闭程序",
        "结束程序",
        "退出软件",
        "关闭软件",
        "退出吧",
        "退出一下",
        "退出了",
        "拜拜",
        "再见"
    });
}

string now_time() {
    time_t t = time(nullptr);
    tm local_tm{};

#ifdef _WIN32
    localtime_s(&local_tm, &t);
#else
    localtime_r(&t, &local_tm);
#endif

    char buf[32];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &local_tm);
    return string(buf);
}

void append_utf8(string& out, int cp) {
    if (cp <= 0x7F) {
        out.push_back((char)cp);
    } else if (cp <= 0x7FF) {
        out.push_back((char)(0xC0 | (cp >> 6)));
        out.push_back((char)(0x80 | (cp & 0x3F)));
    } else if (cp <= 0xFFFF) {
        out.push_back((char)(0xE0 | (cp >> 12)));
        out.push_back((char)(0x80 | ((cp >> 6) & 0x3F)));
        out.push_back((char)(0x80 | (cp & 0x3F)));
    } else {
        out.push_back((char)(0xF0 | (cp >> 18)));
        out.push_back((char)(0x80 | ((cp >> 12) & 0x3F)));
        out.push_back((char)(0x80 | ((cp >> 6) & 0x3F)));
        out.push_back((char)(0x80 | (cp & 0x3F)));
    }
}

int hex_val(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    if ('a' <= c && c <= 'f') return c - 'a' + 10;
    if ('A' <= c && c <= 'F') return c - 'A' + 10;
    return -1;
}

string json_escape(const string& s) {
    string res;

    for (unsigned char ch : s) {
        char c = (char)ch;

        if (c == '"') res += "\\\"";
        else if (c == '\\') res += "\\\\";
        else if (c == '\n') res += "\\n";
        else if (c == '\r') res += "\\r";
        else if (c == '\t') res += "\\t";
        else if (ch < 0x20) {
            const char* h = "0123456789abcdef";
            res += "\\u00";
            res.push_back(h[ch >> 4]);
            res.push_back(h[ch & 15]);
        } else {
            res.push_back(c);
        }
    }

    return res;
}

string json_unescape(const string& s) {
    string res;

    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] != '\\' || i + 1 >= s.size()) {
            res.push_back(s[i]);
            continue;
        }

        char c = s[++i];

        if (c == '"') res.push_back('"');
        else if (c == '\\') res.push_back('\\');
        else if (c == '/') res.push_back('/');
        else if (c == 'b') res.push_back('\b');
        else if (c == 'f') res.push_back('\f');
        else if (c == 'n') res.push_back('\n');
        else if (c == 'r') res.push_back('\r');
        else if (c == 't') res.push_back('\t');
        else if (c == 'u' && i + 4 < s.size()) {
            int cp = 0;
            bool ok = true;

            for (int k = 0; k < 4; k++) {
                int v = hex_val(s[i + 1 + k]);
                if (v < 0) ok = false;
                cp = cp * 16 + max(0, v);
            }

            i += 4;
            if (!ok) continue;

            if (0xD800 <= cp && cp <= 0xDBFF &&
                i + 6 < s.size() &&
                s[i + 1] == '\\' &&
                s[i + 2] == 'u') {

                int lo = 0;
                bool ok2 = true;

                for (int k = 0; k < 4; k++) {
                    int v = hex_val(s[i + 3 + k]);
                    if (v < 0) ok2 = false;
                    lo = lo * 16 + max(0, v);
                }

                if (ok2 && 0xDC00 <= lo && lo <= 0xDFFF) {
                    cp = 0x10000 + ((cp - 0xD800) << 10) + (lo - 0xDC00);
                    i += 6;
                }
            }

            append_utf8(res, cp);
        } else {
            res.push_back(c);
        }
    }

    return res;
}

bool parse_json_string_at(const string& s, size_t quote_pos, string& out) {
    if (quote_pos >= s.size() || s[quote_pos] != '"') return false;

    string raw;
    bool esc = false;

    for (size_t i = quote_pos + 1; i < s.size(); i++) {
        char c = s[i];

        if (esc) {
            raw.push_back('\\');
            raw.push_back(c);
            esc = false;
        } else if (c == '\\') {
            esc = true;
        } else if (c == '"') {
            out = json_unescape(raw);
            return true;
        } else {
            raw.push_back(c);
        }
    }

    return false;
}

bool get_json_string(const string& s, const string& key, string& out, size_t start = 0) {
    string pat = "\"" + key + "\"";
    size_t p = s.find(pat, start);
    if (p == string::npos) return false;

    p = s.find(':', p + pat.size());
    if (p == string::npos) return false;

    p++;
    while (p < s.size() && isspace((unsigned char)s[p])) p++;

    if (p >= s.size() || s[p] != '"') return false;
    return parse_json_string_at(s, p, out);
}

bool get_json_int(const string& s, const string& key, int& out, size_t start = 0) {
    string pat = "\"" + key + "\"";
    size_t p = s.find(pat, start);
    if (p == string::npos) return false;

    p = s.find(':', p + pat.size());
    if (p == string::npos) return false;

    p++;
    while (p < s.size() && isspace((unsigned char)s[p])) p++;

    int sign = 1;
    if (p < s.size() && s[p] == '-') {
        sign = -1;
        p++;
    }

    if (p >= s.size() || !isdigit((unsigned char)s[p])) return false;

    long long val = 0;
    while (p < s.size() && isdigit((unsigned char)s[p])) {
        val = val * 10 + s[p] - '0';
        p++;
    }

    out = (int)(sign * val);
    return true;
}

bool get_json_bool(const string& s, const string& key, bool& out, size_t start = 0) {
    string pat = "\"" + key + "\"";
    size_t p = s.find(pat, start);
    if (p == string::npos) return false;

    p = s.find(':', p + pat.size());
    if (p == string::npos) return false;

    p++;
    while (p < s.size() && isspace((unsigned char)s[p])) p++;

    if (s.compare(p, 4, "true") == 0) {
        out = true;
        return true;
    }

    if (s.compare(p, 5, "false") == 0) {
        out = false;
        return true;
    }

    return false;
}

vector<string> extract_objects_from_array(const string& s, const string& array_key) {
    vector<string> objs;

    string pat = "\"" + array_key + "\"";
    size_t p = s.find(pat);
    if (p == string::npos) return objs;

    p = s.find('[', p + pat.size());
    if (p == string::npos) return objs;

    bool in_str = false;
    bool esc = false;
    int depth = 0;
    size_t obj_start = string::npos;

    for (size_t i = p + 1; i < s.size(); i++) {
        char c = s[i];

        if (in_str) {
            if (esc) esc = false;
            else if (c == '\\') esc = true;
            else if (c == '"') in_str = false;
            continue;
        }

        if (c == '"') {
            in_str = true;
        } else if (c == '{') {
            if (depth == 0) obj_start = i;
            depth++;
        } else if (c == '}') {
            depth--;

            if (depth == 0 && obj_start != string::npos) {
                objs.push_back(s.substr(obj_start, i - obj_start + 1));
                obj_start = string::npos;
            }
        } else if (c == ']' && depth == 0) {
            break;
        }
    }

    return objs;
}

string extract_first_json_object(const string& s) {
    bool in_str = false;
    bool esc = false;
    int depth = 0;
    size_t start = string::npos;

    for (size_t i = 0; i < s.size(); i++) {
        char c = s[i];

        if (in_str) {
            if (esc) esc = false;
            else if (c == '\\') esc = true;
            else if (c == '"') in_str = false;
            continue;
        }

        if (c == '"') {
            in_str = true;
        } else if (c == '{') {
            if (depth == 0) start = i;
            depth++;
        } else if (c == '}') {
            if (depth > 0) depth--;

            if (depth == 0 && start != string::npos) {
                return s.substr(start, i - start + 1);
            }
        }
    }

    return "";
}

bool valid_ai_json(const string& s) {
    string reply;
    if (!get_json_string(s, "reply", reply)) return false;
    if (s.find("\"actions\"") == string::npos) return false;
    return true;
}

string read_file(const string& path) {
    ifstream fin(path, ios::binary);
    if (!fin.is_open()) return "";
    return string((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
}

bool write_file(const string& path, const string& data) {
    ofstream fout(path, ios::binary | ios::trunc);
    if (!fout.is_open()) return false;
    fout << data;
    return true;
}

void append_memory(const string& content) {
    string s = trim(content);
    if (s.empty()) return;

    ofstream fout(MEMORY_FILE, ios::app | ios::binary);
    fout << "[" << now_time() << "] " << s << "\n";
}

void clear_memory() {
    write_file(MEMORY_FILE, "");
}

string load_memory() {
    string s = read_file(MEMORY_FILE);
    if (trim(s).empty()) return "暂无持久化记忆。";
    return s;
}

void save_data(const vector<Task>& tasks, int next_id) {
    ofstream fout(TODO_FILE, ios::out | ios::trunc);

    fout << "{\n";
    fout << "  \"next_id\": " << next_id << ",\n";
    fout << "  \"tasks\": [\n";

    for (size_t i = 0; i < tasks.size(); i++) {
        fout << "    {";
        fout << "\"id\": " << tasks[i].id << ", ";
        fout << "\"done\": " << (tasks[i].done ? "true" : "false") << ", ";
        fout << "\"content\": \"" << json_escape(tasks[i].content) << "\", ";
        fout << "\"created_at\": \"" << json_escape(tasks[i].created_at) << "\", ";
        fout << "\"updated_at\": \"" << json_escape(tasks[i].updated_at) << "\", ";
        fout << "\"due_at\": \"" << json_escape(tasks[i].due_at) << "\", ";
        fout << "\"done_at\": \"" << json_escape(tasks[i].done_at) << "\"";
        fout << "}";

        if (i + 1 < tasks.size()) fout << ',';
        fout << "\n";
    }

    fout << "  ]\n";
    fout << "}\n";
}

void load_data(vector<Task>& tasks, int& next_id) {
    tasks.clear();
    next_id = 1;

    ifstream fin(TODO_FILE);
    if (!fin.is_open()) return;

    string all((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());

    get_json_int(all, "next_id", next_id);

    for (const string& obj : extract_objects_from_array(all, "tasks")) {
        Task t;

        if (!get_json_int(obj, "id", t.id)) continue;

        get_json_bool(obj, "done", t.done);
        get_json_string(obj, "content", t.content);
        get_json_string(obj, "created_at", t.created_at);
        get_json_string(obj, "updated_at", t.updated_at);
        get_json_string(obj, "due_at", t.due_at);
        get_json_string(obj, "done_at", t.done_at);

        if (t.created_at.empty()) t.created_at = "旧数据";
        if (t.updated_at.empty()) t.updated_at = t.created_at;

        tasks.push_back(t);
    }
}

string list_to_string(const vector<Task>& tasks) {
    if (tasks.empty()) return "暂无任务。\n";

    string s;

    for (const auto& t : tasks) {
        s += to_string(t.id);
        s += " [";
        s += (t.done ? "x" : " ");
        s += "] ";
        s += t.content;
        s += "\n";
        s += "    创建时间: " + t.created_at + "\n";

        if (!t.due_at.empty()) {
            s += "    截止时间: " + t.due_at + "\n";
        }

        if (t.done && !t.done_at.empty()) {
            s += "    完成时间: " + t.done_at + "\n";
        }
    }

    return s;
}

string tasks_to_ai_context(const vector<Task>& tasks) {
    if (tasks.empty()) return "当前没有待办。";

    string s;

    for (const auto& t : tasks) {
        s += "编号: " + to_string(t.id) + "\n";
        s += "状态: ";
        s += t.done ? "已完成\n" : "未完成\n";
        s += "内容: " + t.content + "\n";
        s += "创建时间: " + t.created_at + "\n";
        s += "更新时间: " + t.updated_at + "\n";

        if (!t.due_at.empty()) {
            s += "截止时间: " + t.due_at + "\n";
        }

        if (!t.done_at.empty()) {
            s += "完成时间: " + t.done_at + "\n";
        }

        s += "\n";
    }

    return s;
}

void list_tasks(const vector<Task>& tasks) {
    sys_out(list_to_string(tasks));
}

bool add_task(vector<Task>& tasks, int& next_id, const string& content, const string& due_at = "") {
    string s = trim(content);
    if (s.empty()) return false;

    string t = now_time();

    Task task;
    task.id = next_id++;
    task.done = false;
    task.content = s;
    task.created_at = t;
    task.updated_at = t;
    task.due_at = trim(due_at);
    task.done_at = "";

    tasks.push_back(task);
    save_data(tasks, next_id);
    return true;
}

bool done_task(vector<Task>& tasks, int next_id, int id) {
    for (auto& t : tasks) {
        if (t.id == id) {
            t.done = true;
            t.updated_at = now_time();
            t.done_at = t.updated_at;
            save_data(tasks, next_id);
            return true;
        }
    }

    return false;
}

bool delete_task(vector<Task>& tasks, int next_id, int id) {
    size_t old = tasks.size();

    tasks.erase(
        remove_if(tasks.begin(), tasks.end(), [&](const Task& t) {
            return t.id == id;
        }),
        tasks.end()
    );

    if (tasks.size() == old) return false;

    save_data(tasks, next_id);
    return true;
}

void done_all(vector<Task>& tasks, int next_id) {
    string t = now_time();

    for (auto& task : tasks) {
        task.done = true;
        task.updated_at = t;
        task.done_at = t;
    }

    save_data(tasks, next_id);
}

int delete_done(vector<Task>& tasks, int next_id) {
    int old = (int)tasks.size();

    tasks.erase(
        remove_if(tasks.begin(), tasks.end(), [](const Task& t) {
            return t.done;
        }),
        tasks.end()
    );

    save_data(tasks, next_id);
    return old - (int)tasks.size();
}

void clear_all(vector<Task>& tasks, int& next_id) {
    tasks.clear();
    next_id = 1;
    save_data(tasks, next_id);
}

bool is_number(const string& s) {
    if (s.empty()) return false;

    for (char c : s) {
        if (!isdigit((unsigned char)c)) return false;
    }

    return true;
}

string get_api_key() {
    const char* env = getenv("DEEPSEEK_API_KEY");

    if (env && *env) return string(env);

    ifstream fin("deepseek_key.txt");

    if (fin.is_open()) {
        string key;
        getline(fin, key);
        key = trim(key);

        if (!key.empty()) return key;
    }

    return "";
}

string msg_json(const string& role, const string& content) {
    return "{\"role\":\"" + json_escape(role) + "\",\"content\":\"" + json_escape(content) + "\"}";
}

string build_request_json(
    const vector<Task>& tasks,
    const vector<Msg>& history,
    const string& user_input,
    const string& retry_note
) {
    string system_prompt =
        "你是一个中文命令行 To-Do List 助手。"
        "你必须只输出 JSON，绝对不要 Markdown，不要代码块，不要解释 JSON。"
        "固定格式：{\"reply\":\"给用户看的简短中文回复\",\"actions\":[...]}。"
        "actions 只能使用以下动作："
        "{\"type\":\"add\",\"content\":\"任务内容\",\"due_at\":\"可选截止时间\"},"
        "{\"type\":\"done\",\"id\":编号},"
        "{\"type\":\"delete\",\"id\":编号},"
        "{\"type\":\"done_all\"},"
        "{\"type\":\"delete_done\"},"
        "{\"type\":\"clear\"},"
        "{\"type\":\"list\"},"
        "{\"type\":\"remember\",\"content\":\"需要长期记住的用户偏好或角色设定\"},"
        "{\"type\":\"clear_memory\"},"
        "{\"type\":\"exit\"}。"
        "如果用户表达想退出、关闭程序、结束程序、拜拜、再见，必须使用 exit。"
        "如果用户问怎么使用工具，要直接用中文解释，不需要 actions。"
        "如果用户说添加、记一下、帮我安排，就使用 add。"
        "如果用户给了时间，例如明天、今晚八点、周五，把原文时间放到 due_at。"
        "如果用户说完成所有、全部完成、解决所有问题，使用 done_all。"
        "如果用户说删除已完成，使用 delete_done。"
        "如果用户说清空任务、清除所有记录、删除全部任务，使用 clear。"
        "如果用户问现在有什么任务，使用 list，reply 不要重复任务列表。"
        "如果用户告诉你角色设定或长期偏好，例如“你是一只猫娘”“以后说话简短点”，必须使用 remember。"
        "如果用户只说“对/是/好的”，结合上文判断。"
        "不要谎称已经执行，真正的执行结果由程序输出。"
        "回复要自然，中文为主，可以带少量颜文字。";

    string req = "{";

    req += "\"model\":\"" + json_escape(MODEL) + "\",";
    req += "\"messages\":[";

    req += msg_json("system", system_prompt);
    req += "," + msg_json("user", "当前持久化记忆：\n" + load_memory());
    req += "," + msg_json("user", "当前真实待办列表：\n" + tasks_to_ai_context(tasks));

    int start = max(0, (int)history.size() - 10);

    for (int i = start; i < (int)history.size(); i++) {
        req += "," + msg_json(history[i].role, history[i].content);
    }

    string final_input = user_input;

    if (!retry_note.empty()) {
        final_input += "\n\n系统重试提示：" + retry_note;
    }

    req += "," + msg_json("user", final_input);
    req += "],";

    req += "\"response_format\":{\"type\":\"json_object\"},";
    req += "\"temperature\":0.2,";
    req += "\"max_tokens\":1000";

    req += "}";

    return req;
}

bool call_deepseek_once(
    const vector<Task>& tasks,
    const vector<Msg>& history,
    const string& user_input,
    const string& retry_note,
    string& raw_content,
    string& raw_response
) {
    string api_key = get_api_key();

    if (api_key.empty()) {
        err_out("没有找到 DeepSeek API Key。请设置 DEEPSEEK_API_KEY，或者在同目录创建 deepseek_key.txt。");
        return false;
    }

    const string req_path = ".todo_ai_request.json";
    const string res_path = ".todo_ai_response.json";
    const string cfg_path = ".todo_ai_curl.cfg";

    write_file(req_path, build_request_json(tasks, history, user_input, retry_note));

    string cfg;

    cfg += "silent\n";
    cfg += "show-error\n";
    cfg += "location\n";
    cfg += "request = \"POST\"\n";
    cfg += "url = \"" + API_URL + "\"\n";
    cfg += "header = \"Content-Type: application/json\"\n";
    cfg += "header = \"Authorization: Bearer " + api_key + "\"\n";
    cfg += "data = @" + req_path + "\n";
    cfg += "output = \"" + res_path + "\"\n";

    write_file(cfg_path, cfg);

#ifdef _WIN32
    string cmd = "curl.exe -K \"" + cfg_path + "\"";
#else
    string cmd = "curl -K \"" + cfg_path + "\"";
#endif

    int code = system(cmd.c_str());

    remove(cfg_path.c_str());
    remove(req_path.c_str());

    if (code != 0) {
        err_out("curl 调用失败。请检查网络，以及系统里是否有 curl。");
        return false;
    }

    raw_response = read_file(res_path);
    remove(res_path.c_str());

    if (raw_response.empty()) {
        err_out("DeepSeek 返回为空。");
        return false;
    }

    string content;

    if (!get_json_string(raw_response, "content", content)) {
        return false;
    }

    raw_content = trim(content);
    return true;
}

bool call_deepseek(
    const vector<Task>& tasks,
    const vector<Msg>& history,
    const string& user_input,
    string& ai_json
) {
    string retry_note;

    for (int attempt = 1; attempt <= 3; attempt++) {
        string raw_content;
        string raw_response;

        bool ok = call_deepseek_once(
            tasks,
            history,
            user_input,
            retry_note,
            raw_content,
            raw_response
        );

        if (!ok) {
            retry_note =
                "你上一次没有返回可解析的 content。"
                "请严格返回 JSON：{\"reply\":\"...\",\"actions\":[]}。";

            if (attempt == 3) {
                err_out("DeepSeek 响应解析失败。原始响应片段如下：");
                cerr << raw_response.substr(0, 800) << "\n";
                return false;
            }

            continue;
        }

        string obj = extract_first_json_object(raw_content);

        if (valid_ai_json(obj)) {
            ai_json = obj;
            return true;
        }

        retry_note =
            "你上一次输出不是合法 JSON，或者缺少 reply/actions。"
            "请不要输出自然语言解释，不要 Markdown，只输出："
            "{\"reply\":\"中文回复\",\"actions\":[]}。"
            "如果用户想退出，必须输出："
            "{\"reply\":\"好的，已退出。\",\"actions\":[{\"type\":\"exit\"}]}。"
            "上一次输出为：" + raw_content.substr(0, 500);
    }

    err_out("DeepSeek 连续返回了无法解析的 JSON。");
    return false;
}

string apply_ai_result(vector<Task>& tasks, int& next_id, const string& ai_json, bool& should_exit) {
    string reply;

    get_json_string(ai_json, "reply", reply);

    vector<string> actions = extract_objects_from_array(ai_json, "actions");

    string syslog;

    if (!trim(reply).empty()) {
        ai_out(reply);
    }

    for (const string& act : actions) {
        string type;

        if (!get_json_string(act, "type", type)) continue;

        if (type == "add") {
            string content;
            string due_at;

            get_json_string(act, "content", content);
            get_json_string(act, "due_at", due_at);

            int id = next_id;

            if (add_task(tasks, next_id, content, due_at)) {
                string s = "已添加任务 #" + to_string(id) + "：" + trim(content);

                if (!trim(due_at).empty()) {
                    s += "，截止时间：" + trim(due_at);
                }

                s += "\n";

                sys_out(s);
                syslog += s;
            }
        } else if (type == "done") {
            int id;

            if (get_json_int(act, "id", id)) {
                if (done_task(tasks, next_id, id)) {
                    string s = "已完成任务 #" + to_string(id) + "\n";
                    sys_out(s);
                    syslog += s;
                } else {
                    string s = "没有找到任务 #" + to_string(id) + "\n";
                    sys_out(s);
                    syslog += s;
                }
            }
        } else if (type == "delete") {
            int id;

            if (get_json_int(act, "id", id)) {
                if (delete_task(tasks, next_id, id)) {
                    string s = "已删除任务 #" + to_string(id) + "\n";
                    sys_out(s);
                    syslog += s;
                } else {
                    string s = "没有找到任务 #" + to_string(id) + "\n";
                    sys_out(s);
                    syslog += s;
                }
            }
        } else if (type == "done_all") {
            done_all(tasks, next_id);

            string s = "已将所有任务标记为完成。\n";
            sys_out(s);
            syslog += s;
        } else if (type == "delete_done") {
            int cnt = delete_done(tasks, next_id);

            string s = "已删除完成任务：" + to_string(cnt) + " 项。\n";
            sys_out(s);
            syslog += s;
        } else if (type == "clear") {
            clear_all(tasks, next_id);

            string s = "已清空所有任务。\n";
            sys_out(s);
            syslog += s;
        } else if (type == "list") {
            string s = list_to_string(tasks);

            sys_out(s);
            syslog += s;
        } else if (type == "remember") {
            string content;

            if (get_json_string(act, "content", content)) {
                append_memory(content);

                string s = "已写入长期记忆。\n";
                sys_out(s);
                syslog += s;
            }
        } else if (type == "clear_memory") {
            clear_memory();

            string s = "已清空长期记忆。\n";
            sys_out(s);
            syslog += s;
        } else if (type == "exit") {
            should_exit = true;

            string s = "程序即将退出。\n";
            sys_out(s);
            syslog += s;
        }
    }

    if (syslog.empty()) {
        syslog = "无系统动作。\n";
    }

    return "AI回复：" + reply + "\n系统执行结果：\n" + syslog;
}

void print_help() {
    cout << "命令：\n";
    cout << "  添加 / add <任务内容>          添加任务\n";
    cout << "  列表 / list                   查看任务\n";
    cout << "  完成 / done <编号>             标记完成\n";
    cout << "  删除 / delete <编号>           删除任务\n";
    cout << "  help                           进入 DeepSeek 对话模式\n";
    cout << "  帮助 / commands                显示本帮助\n";
    cout << "  退出 / exit                    退出程序\n";
}

bool local_command(vector<Task>& tasks, int& next_id, const string& input, bool verbose, bool& should_exit) {
    string line = trim(input);

    if (line.empty()) return true;

    if (line == "exit" || line == "quit" || line == "退出" || line == "退出程序") {
        should_exit = true;
        return true;
    }

    stringstream ss(line);
    string cmd;

    ss >> cmd;

    if (cmd == "add" || cmd == "添加") {
        string content;
        getline(ss, content);

        bool ok = add_task(tasks, next_id, content);

        if (verbose) {
            sys_out(ok ? "已添加。\n" : "任务内容为空。\n");
        }

        return true;
    }

    if (cmd == "list" || cmd == "列表" || cmd == "查看") {
        list_tasks(tasks);
        return true;
    }

    if (cmd == "done" || cmd == "完成") {
        string id;

        ss >> id;

        bool ok = is_number(id) && done_task(tasks, next_id, stoi(id));

        if (verbose) {
            sys_out(ok ? "已完成。\n" : "编号无效。\n");
        }

        return true;
    }

    if (cmd == "delete" || cmd == "删除") {
        string id;

        ss >> id;

        bool ok = is_number(id) && delete_task(tasks, next_id, stoi(id));

        if (verbose) {
            sys_out(ok ? "已删除。\n" : "编号无效。\n");
        }

        return true;
    }

    if (cmd == "clear" || cmd == "清空") {
        clear_all(tasks, next_id);

        if (verbose) {
            sys_out("已清空所有任务。\n");
        }

        return true;
    }

    if (cmd == "memory" || cmd == "记忆") {
        sys_out(load_memory() + "\n");
        return true;
    }

    if (cmd == "clearmemory" || cmd == "清空记忆") {
        clear_memory();
        sys_out("已清空长期记忆。\n");
        return true;
    }

    return false;
}

bool fallback_intent(vector<Task>& tasks, int& next_id, const string& line, bool& should_exit) {
    string s = trim(line);

    if (s.empty()) return true;

    if (wants_exit_phrase(s)) {
        should_exit = true;
        sys_out("程序即将退出。\n");
        return true;
    }

    if (contains_any(s, {"清空任务", "清除所有", "删除全部", "清楚所有", "清空所有"})) {
        clear_all(tasks, next_id);
        sys_out("已清空所有任务。\n");
        return true;
    }

    if (contains_any(s, {"完成所有", "全部完成", "全都完成", "都完成", "解决所有问题"})) {
        done_all(tasks, next_id);
        sys_out("已将所有任务标记为完成。\n");
        return true;
    }

    if (contains_any(s, {"删除已完成", "清除已完成", "移除已完成"})) {
        int cnt = delete_done(tasks, next_id);
        sys_out("已删除完成任务：" + to_string(cnt) + " 项。\n");
        return true;
    }

    return false;
}

void ask_ai_once(
    vector<Task>& tasks,
    int& next_id,
    vector<Msg>& history,
    const string& line,
    bool& should_exit
) {
    string ai_json;

    if (call_deepseek(tasks, history, line, ai_json)) {
        string result = apply_ai_result(tasks, next_id, ai_json, should_exit);

        if (!should_exit && wants_exit_phrase(line)) {
            should_exit = true;
            sys_out("程序即将退出。\n");
            result += "\n系统兜底：检测到用户想退出，已设置退出。\n";
        }

        history.push_back({"user", line});
        history.push_back({"assistant", result});
    } else {
        fallback_intent(tasks, next_id, line, should_exit);
    }
}

void ai_mode(vector<Task>& tasks, int& next_id, vector<Msg>& history, bool& should_exit) {
    cout << "DeepSeek 对话模式。输入 back 返回主界面，输入 退出 直接退出程序。\n";

    string line;

    while (!should_exit) {
        cout << "ai> ";

        if (!getline(cin, line)) break;

        line = trim(line);

        if (line.empty()) continue;

        if (line == "back" || line == "返回") {
            break;
        }

        if (local_command(tasks, next_id, line, true, should_exit)) {
            continue;
        }

        ask_ai_once(tasks, next_id, history, line, should_exit);
    }
}

void run_command(
    vector<Task>& tasks,
    int& next_id,
    vector<Msg>& history,
    const string& input,
    bool& should_exit
) {
    string line = trim(input);

    if (line.empty()) return;

    if (line == "commands" || line == "帮助" || line == "命令") {
        print_help();
        return;
    }

    if (line == "help") {
        ai_mode(tasks, next_id, history, should_exit);
        return;
    }

    if (local_command(tasks, next_id, line, false, should_exit)) {
        return;
    }

    ask_ai_once(tasks, next_id, history, line, should_exit);
}

int main(int argc, char* argv[]) {
    init_console();

    vector<Task> tasks;
    int next_id;
    vector<Msg> history;
    bool should_exit = false;

    load_data(tasks, next_id);

    if (argc >= 2) {
        string cmd = argv[1];

        if (cmd == "commands" || cmd == "帮助" || cmd == "命令") {
            print_help();
            return 0;
        }

        if (cmd == "help") {
            ai_mode(tasks, next_id, history, should_exit);
            return 0;
        }

        string line = cmd;

        for (int i = 2; i < argc; i++) {
            line += " ";
            line += argv[i];
        }

        run_command(tasks, next_id, history, line, should_exit);
        return 0;
    }

    cout << "To-Do List 命令行工具\n";
    print_help();

    string line;

    while (!should_exit) {
        cout << "\ntodo> ";

        if (!getline(cin, line)) break;

        run_command(tasks, next_id, history, line, should_exit);
    }

    return 0;
}