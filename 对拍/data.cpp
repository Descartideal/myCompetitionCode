#include <bits/stdc++.h>
using namespace std;

int main(){
    srand(time(0));
    cout<<1<<endl;
    int n = rand()%6+1;
    int k = rand()%n + 1;
    for(int i=1;i<=n;++i){
        cout<<rand()%n+1<<" ";
    }cout<<endl;
    
    return 0;
}