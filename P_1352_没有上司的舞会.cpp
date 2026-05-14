#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> r(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> r[i];
    }
    vector<int> fu(n + 1, -1);
    vector<vector<int>> son(n + 1);

    vector<int> ru(n + 1, 0), chu(n + 1, 0);

    for (int i=1;i<n;++i) {
        int x, y;
        cin >> x >> y;
        fu[x] = y;
        son[y].push_back(x);

        ++ru[y];
        ++chu[x];
    }

    int root;
    for (int i = 1; i <= n; ++i) {
        if (fu[i] == -1) {
        root = i;
        break;
        }
    }

    vector<int> dp(n+1,0);
    queue<int> q;

    for (int i = 1; i <= n; ++i) {
        if (ru[i] == 0) {
        q.push(i);
        }
    }

    while (!q.empty()) {
        int x = q.front();q.pop();
        int y = fu[x];

        if (son[x].size() == 0) {
            dp[x] = max(0, r[x]);
        } else {
            int sum1 = 0;
            for(int xx:son[x]){
                sum1 += dp[xx];
            }

            int sum2 = 0;
            for(int xx:son[x]){
                for(int xxx:son[xx]){
                    sum2 += dp[xxx];
                }
            }
            dp[x] = max(r[x]+sum2, sum1);
        }
        if(x==root)break;
        --ru[y];
        if(ru[y] == 0){
            q.push(y);
        }
    }
    cout << dp[root] << endl;
    return 0;
}