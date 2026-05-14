#include <bits/stdc++.h>
using namespace std;

#define d(x) cerr<<"#---"<<#x<<"=="<<x<<"\n";
#define int long long

template<class T>
ostream& operator<<(ostream& os,const pair<T,T> v){
    os<<v.first<<","<<v.second<<" ";
    return os;
}

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v)os<<x<<" ";
    //os<<'\n';
    return os;
}


void solve(){
    string s;cin>>s;
    vector<int> even(3 , 0) ; vector<int> odd(3 , 0);
    int n = s.length();
    for(int i = 0 ; i < n ; i ++){
        if(i % 2 == 0){
            even[s[i] - '0']++;
        }
        else{
            odd[s[i] - '0']++;
        }
    }

    for(int i = 0 ; i < 2 ; i ++){
        int tmp = min(even[i] , odd[i]);
        even[i] -= tmp;
        odd[i] -= tmp;
    }

    for(int i = 0 ; i < 2 ; i ++){
        int tmp = min(even[i] , odd[2]);
        even[i] -= tmp;
        odd[2] -= tmp;
    }
    for(int i = 0 ; i < 2 ; i ++){
        int tmp = min(odd[i] , even[2]);
        odd[i] -= tmp;
        even[2] -= tmp;
    }
      
    int tmp = min(odd[2] , even[2]);
    odd[2] -= tmp;
    even[2] -= tmp;    

    int ans = 0;
    for(int i = 0 ; i < 3 ; i ++){
        ans += even[i];
        ans += odd[i];
    }

    cout<<ans<<endl;
}

signed main(){
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}