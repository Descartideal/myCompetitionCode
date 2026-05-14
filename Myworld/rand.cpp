#include <bits/stdc++.h>
using namespace std;

int a[5] = {3697 ,9260 ,31322 ,672, 5770};

signed main(){
    int n = 1000000000;

    for(int i=0;i<=n;++i){
        int seed = i;
        srand(seed);
        
        bool j = 1;
        for(int x:a){
            if(x!=rand()){
                j=0;
                break;
            }
        }

        if(j){
            cout<<"Unika!!!: "<<seed<<endl;
            break;
        }
        
        if(i%1000000==0)cout<<i<<endl;
    }
}