#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+20;
int n,m;

struct node{
    int add=0;
    int lad=0;
    int lmu=1;

    int lson=-1,rson=-1;
};

node tr[N<<2];

void pu(){

}

void pd(){
    
}

int main(){
    int q;cin>>n>>q>>m;

    for(int i=1;i<=q;++i){
        int op,x,y,z;cin>>op>>x>>y;
        if(op==1){
            cin>>z;
        }else if(op==2){
            cin>>z;
        }else{

        }
    }

    return 0;
}