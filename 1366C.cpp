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

inline void solve(){
    int n,m;cin>>n>>m;
    vector<vector<int>> a(n+1,vector<int>(m+1));
    int D = n+m-1;int huo = 0;
    if(D&1)huo = (D+1)/2;

    vector<int> ans0(D+1,0),ans1(D+1,0);

    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>a[i][j];

            int d = i+j-1;
            
            if(d==huo)continue;
            if(d>D/2){
                if(D&1){
                    d = D+1-d;
                }else{
                    d = D+1-d;
                }
            }

            if(a[i][j]){
                ans1[d]++;
            }else{
                ans0[d]++;
            }
        }
    }
    //cerr<<huo<<" "<<ans0<<" "<<ans1<<endl;
    int ans = 0;
    for(int i=1;i<=D;++i){
        ans += min(ans0[i],ans1[i]);
    }

    cout<<ans<<endl;

	return;
}


signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
	int t;cin>>t;
	while(t-->0){
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