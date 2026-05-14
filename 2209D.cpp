#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

using i64 = long long;
using ll = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

using b32 = bitset<32>;
using b64 = bitset<64>;

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v)os<<x<<" ";
    return os;
}

template<class T>
istream& operator>>(istream& is, vector<T>& v){
    for(auto& x:v)is>>x;
    return is;
}

struct p{
    int cnt;char color;
};

bool comp(p a,p b){
    return a.cnt<b.cnt;
}

inline void solve(){
    vector<p> a(3);
    for(int i=0;i<3;++i){
        cin>>a[i].cnt;
    }
    a[0].color='R';a[1].color='G';a[2].color='B';
    sort(a.begin(),a.end(),comp);
    while(a[0].cnt+a[1].cnt>a[2].cnt){
        cout<<a[0].color<<a[1].color;
        a[0].cnt--;a[1].cnt--;
    }
    
    for(int i=1;i<=a[1].cnt;++i)cout<<a[2].color<<a[1].color;
    for(int i=1;i<=a[0].cnt;++i)cout<<a[2].color<<a[0].color;
    if(a[2].cnt>a[1].cnt+a[0].cnt)cout<<a[2].color;
    cout<<endl;
	return;
}


signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}


















/*
***** Orz  Kiropo *******
*　　┏┓　　　┏┓+ +
*　┏┛┻━━━┛┻┓ + +
*　┃　　　　　　　┃
*　┃　　　━　　　┃ ++ + + +
*  ████━████+
*  ◥██◤　◥██◤ +
*　┃　　　┻　　　┃
*　┃　　　　　　　┃ + +
*　┗━┓　　　┏━┛
*　　　┃　　　┃ + + + +Code is far away from 　
*　　　┃　　　┃ + bug with the animal protecting
*　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
*　　　┃ 　　　　　　 ┣┓
*　　  ┃ 　　　　　 　┏┛
*　    ┗┓┓┏━┳┓┏┛ + + + +
*　　　　┃┫┫　┃┫┫
*　　　　┗┻┛　┗┻┛+ + + +
*/

//————自由是遗忘的左伴随


/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣤⡀⣀⣠⣤⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⡀⢀⣴⣾⣷⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣷⣾⣿⣷⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⠿⠛⠛⠉⠉⠉⠉⠉⠉⠛⠻⠿⣿⣿⣿⣿⣿⣶⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⡿⠿⠛⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠿⣿⣿⣿⣷⣄⡀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣀⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⣰⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠿⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣠⣾⣿⣿⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣶⣄⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣻⣿⣿⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢹⣿⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⠁⠈⢢⡀⠀⠀⠀⢸⡇⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⡟⠒⢦⡀⠀⠀⠀
⠀⠀⣠⣤⣤⣼⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⡇⠀⠀⠀⠉⢢⣄⠀⠀⢿⠊⠳⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣷⡄⠀⢷⠀⠀⠀
⠀⢰⠇⠀⣰⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⡌⣹⠗⠦⣬⣇⠀⠉⢢⡀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⡀⢸⡄⠀⠀
⠀⡟⠀⣼⣯⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣆⢹⡀⠀⠀⠀⠉⠁⠀⠀⢀⣀⡁⠀⠀⠉⠳⢴⡆⠀⠀⠀⠀⠀⠀⢹⣧⠈⡇⠀⠀
⠀⡇⠀⠀⢻⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣾⠻⠉⠛⠂⠀⠀⠀⠀⠀⠀⠻⠿⣿⣿⣿⣶⣦⡀⠛⣇⠀⠀⠀⠀⠀⣈⣿⠀⡇⠀⠀
⢸⡇⠀⠀⢠⣿⣷⣦⣀⡸⣷⣦⣶⡂⠉⠉⠉⢁⣤⣶⡶⠀⠀⠀⣀⣀⡴⠀⠀⠀⠀⠀⠀⠈⠉⠉⠁⠀⡟⢀⣴⣟⣰⣾⣿⣏⣠⠇⠀⠀
⠈⡇⠀⠀⢸⣿⠁⠉⣿⠛⠛⠃⡇⠀⠀⢠⣶⣿⡿⠛⠁⠀⠀⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠼⢿⠟⠿⢿⡏⠀⠘⣿⡀⠀⠀⠀
⠀⢷⣀⣀⣿⠇⠀⠀⢿⡇⠀⢀⢱⡀⠀⠛⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠀⠀⢸⠇⠀⠀⢹⣿⣄⠀⠀
⠀⠀⣉⣿⡏⠀⠀⠀⠀⠀⠀⢸⣇⣳⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡰⣿⠃⠀⠀⠀⠀⠀⠀⣿⠈⢧⠀
⠀⠘⣿⣿⠁⠀⠀⠀⠀⠀⠀⠘⣿⡛⣶⠀⠀⣠⠔⠒⠛⠒⠦⡀⠀⠀⠀⠀⣠⡤⠶⠤⢤⣀⠀⠀⠀⢀⣏⡄⠀⠀⠀⠀⠀⡀⣿⡆⠈⣧
⣠⡾⠛⣿⣿⣧⠀⠀⠀⠀⢸⣿⠾⢿⡿⠀⣰⠃⠀⠀⠀⠀⠀⢹⡄⠀⠀⡼⠁⠀⠀⠀⠀⠈⠙⣦⠀⢸⣿⡇⣾⣣⡀⠀⢰⣿⣿⣿⣤⠾
⡟⠀⠀⠻⣿⡟⢷⡄⣤⡀⠈⣿⡀⣸⠇⠀⠏⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⡇⢀⡀⠀⠀⠀⠀⢀⡟⠀⠀⠋⣿⣿⣿⡇⣠⣿⠿⠛⢷⡀⠀
⠀⠀⠀⠀⣿⣇⣨⣿⣿⣿⣦⣽⣷⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠃⠀⠙⠢⠤⠤⠴⢾⠀⠀⠀⠀⢸⣷⣿⣿⠟⠁⠀⠀⠈⣧⠀
⠀⠀⠀⠀⠈⠉⠉⠁⠈⠉⠈⢉⣿⡁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⣿⠀
*/