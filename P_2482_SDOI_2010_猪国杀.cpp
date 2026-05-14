#include <bits/stdc++.h>
using namespace std;

struct Cards{
    int K,D,P,F,N,W,J,Z;
    list<char> card;
    
};

struct Pig{
    string Identity;
    
};

signed main(){
    int NumberOfPigs,NumberOfCards;cin>>NumberOfPigs>>NumberOfCards;
    vector<string> IdentityOfPigs(NumberOfPigs+1);
    for(int i=1;i<=NumberOfPigs;++i){
        cin>>IdentityOfPigs[i];
    }

    list<char> a;
    
    
}