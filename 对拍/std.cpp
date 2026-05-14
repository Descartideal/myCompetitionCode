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

#define d(x) cerr<<"#---"<<#x<<"=="<<x<<endl;



#define int long long
const int INF = 1e9+7;

void solve(){
    int n,a,d,m,k;cin>>n>>a>>d>>m>>k;

    int cntA;

    if(k>0){
        if(d<=k){
            cntA = 0;
        }else{
            cntA = (d-1)/k;
        }
        
    }else{
        if(d!=0)cntA = INF;
        else cntA = 0;
    }

    if(cntA<0LL)cntA=0LL;

    int state = 0;
    if(cntA==0){
        state = 1+m;
    }else{
        state = n+m;

        int re = m/cntA;
        re = min(re,n-1);
        state -= re;
    }
    

    cout<<state<<'\n';
	return;
}

signed main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    //t = 1;
    while(t --){
        solve();
    }
    
    return 0;
}