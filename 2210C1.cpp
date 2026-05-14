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

int mgcd(int x,int y){
    if(x>y)swap(x,y);
    if(x==0)return y;
    return mgcd(y%x,x);
}

inline void solve(){
    int n;cin>>n;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)cin>>b[i];
    vector<int> g(n);
    for(int i=1;i<=n-1;++i){
        g[i] = mgcd(a[i],a[i+1]);
    }

    int ans = 0;
    for(int i=2;i<=n-1;++i){
        if(g[i-1]!=a[i] && a[i]!=g[i]){
            if( (g[i-1]%g[i]==0)||(g[i]%g[i-1]==0) ){ans++;}
        }
    }
    if(g[1]!=a[1]){
        ans++;
    }
    if(g[n-1]!=a[n]){
        ans++;
    }
    cout<<ans<<endl;
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