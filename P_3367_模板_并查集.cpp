#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;cin>>n>>m;
    vector<int> a(n+1,-1);
    for(int i=1;i<=n;++i){
        a[i] = i;
    }

    function<int(int)> find;
    find = [&](int x){
        if(x==a[x])return x;
        return a[x]=find(a[x]);
    };

    for(int i=1;i<=m;++i){
        int op,x,y;cin>>op>>x>>y;
        if(op==1){
            if(find(x) != find(y)){
                a[find(x)] = a[find(y)];
            }
        }else{
            if(find(x) != find(y)){
                cout<<"N\n";
            }else{
                cout<<"Y\n";
            }
        }
    }


    return 0;
}