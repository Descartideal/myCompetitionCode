//teamname: The Farce is Over
//Acmer: Descartideal

#include <bits/stdc++.h>
using namespace std;

#define int long long

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


#define d(x) cerr<<"#---"<<#x<<"=="<<x<<endl;
#define cerr if(0)cerr

inline void solve(){ 
    int n;cin>>n;d(n)
    int nStart = n;
    vector<string> a(n+2);for(int i=1;i<=n;++i)cin>>a[i];
    int b[6][6][46];
    for(int i=0;i<=5;++i){
        for(int j=0;j<=5;++j){
            for(int k=0;k<=45;++k){
                b[i][j][k] = 0;
            }
        }
    }

    for(int ii=1;ii<=n;++ii){
        string s = a[ii];d(s)
        int len = s.size();d(len)
        vector<int> t(len+1,0);
        for(int i=1;i<=len;++i){
            t[i] = s[i-1]-'0';
        }
        for(int nlen=len;nlen>=1;nlen-=2){d(nStart)
            int w = 0;
            for(int i=1;i<=(len+nlen)/2;++i){
                w += t[i];
            }
            for(int i=(len+nlen)/2+1;i<=len;++i){
                w -= t[i];
            }
            if(w>=1){d(w)
                b[len][nlen][w]++;
                d(len)d(nlen)d(w)
                d(b[len][nlen][w])
            }
        }
        cerr<<"the farce is over------------"<<endl;
        for(int nlen=len+2;nlen<=5;nlen+=2){d(nStart)
            int w = 0;
            for(int i=1;i<=len;++i){
                w += t[i];
            }
            b[len][nlen][w]++;
            d(len)d(nlen)d(w)
            d(b[len][nlen][w])
        }cerr<<endl<<endl;;
    }

    ll ans = 0;
    for(int i=1;i<=n;++i){
        string s = a[i];
        int len = s.size();
        vector<int> t(len+1,0);
        for(int i=1;i<=len;++i){
            t[i] = s[i-1]-'0';
        }
        d(t)d(s)cerr<<endl;

        for(int nlen=len;nlen>=1;nlen-=2){
            d(len-nlen+1)
            int w = 0;
            for(int i=len;i>=(len-nlen)/2+1;--i){
                w += t[i];
            }
            for(int i=1;i<=(len-nlen)/2;++i){
                w -= t[i];
            }
            
            if(w>=1){
                d(nlen)d(len)d(w)
                ans += b[nlen][len][w];
            }
        }
        for(int nlen=len+2;nlen<=5;nlen+=2){
            int w = 0;
            for(int i=1;i<=len;++i){
                w += t[i];
            }
            d(nlen)d(len)d(w)
            ans += b[nlen][len][w];
        }
    }

    cout<<ans<<endl;
	return;
}


signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
	solve();
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