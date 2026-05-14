#include <bits/stdc++.h>
using namespace std;

#define int long long

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v)os<<x<<" ";
    return os;
}

int solve(int n){
    vector<int> p;

    int v = (sqrt(n)+4);
    for(int i=2;i<=v;++i){
        while(n%i==0){
            n/=i;
            p.push_back(i);
        }
    }
    p.push_back(n);

    //cerr<<p<<endl;

    set<int> b;
    for(int x:p){
        b.insert(x);
    }

    unordered_map<int,int> c;
    for(int x:p){
        c[x]++;
    }

    int ans = 1;
    for(int x:b){
        if(x==1 || x==2)continue;
        int t = c[x];
        if(x%4==1){
            ans *= (2*t+1);
        }
    }
    return 4*ans;
}

signed main(){
    int n;cin>>n;
    cout<<solve(n);
    return 0;
}