#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;cin>>n;int q;cin>>q;
    vector<bool> isPrime(n+1,1);
    vector<int> p;

    for(int i=2;i<=n;++i){
        if(isPrime[i]){
            p.push_back(i);
        }

        for(int j=0;j<p.size()&&i*p[j]<=n;++j){
            isPrime[i*p[j]]=0;
            if(i%p[j]==0)break;
        }
    }

    for(int i=1;i<=q;++i){
        int x;cin>>x;
        cout<<p[x-1]<<"\n";
    }
}