#include <bits/stdc++.h>
using namespace std;

int main(){
    int h,w,k,i,t;cin>>h>>w>>k>>i>>t;
    vector<vector<char>> a(h+1,vector<char>(w+1));

    k--;i--;t--;
    a[1][1]='K';
    a[1][2]='I';
    a[1][3]='T';

    for(int ii=1;ii<=h;++ii){
        for(int j=1;j<=w;++j){
            if(ii==1 && j<=3)continue;
            char& c = a[ii][j];

            if(k>0){
                c = 'K';
                k--;
                continue;
            }
            if(t>0){
                c = 'T';
                t--;
                continue;
            }
            if(i>0){
                c = 'I';
                i--;
                continue;
            }
        }
    }

    for(int ii=1;ii<=h;++ii){
        for(int j=1;j<=w;++j){
            cout<<a[ii][j];
        }cout<<endl;
    }


    return 0;
}