#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+7;
int a[N+100];

int mgcd(int a,int b){
    if(a>b)swap(a,b);
    if(a==0)return b;
    return mgcd(b%a,a);
}

int mex(vector<int> a){
    sort(a.begin(),a.end());
    int cnt = 0;
    for(int x:a){
        if(x==cnt){
            cnt++;
        }
    }
    return cnt;
}

signed main(){
    int n = 1000;
    a[1] = 1;
    for(int i=2;i<=n;++i){
        vector<int> t;
        for(int j=1;j<=i-1;++j){
            if(mgcd(j,i)==1){
                t.push_back(a[j]);
            }
        }

        a[i] = mex(t);
    }

    for(int i=0;i<=n;++i){
        for(int j=1;j<=10;++j){
            cout<<a[i*10+j]<<"   ";
        }cout<<endl;
    }
}