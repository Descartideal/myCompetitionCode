#include <bits/stdc++.h>
#ifdef __unix__
#define gc getchar_unlocked
#else
#define gc _getchar_nolock
#endif

using namespace std;
int fastint(){
    int c = gc();
    while( c!=EOF && !isdigit(c) )c=gc();
    int r=0;
    while(isdigit(c)){
        r*=10;r+=c-'0';
        c = gc();
    }
    return r;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n=fastint();
    vector<int> a(n+1.0),l(n+1,0),r(n+1,0);
    for(int i=1;i<=n;++i){
        int x=fastint();
        
    }

    return 0;
}