#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isarea(int n){
    int m = sqrt(n);
    m -= 10;
    for(int i=0;i<=20;++i){
        m++;
        if(m*m==n)break;
    }
    if(m*m==n){
        return 1;
    }else{
        return 0;
    }
}

int holes_cnt[26] = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};

int holeCnt(const string& s){
    int cnt = 0;
    for(char c:s){
        int n = c-'A';
        cnt += holes_cnt[n];
    }
    return cnt;
}

signed main(){
    string s;cin>>s;
    

    int ans = 0;
    for(int i=0;i<26;++i){
        for(char& c:s){
            c += 1;
            if(c>'Z')c-=26;
        }

        if(holeCnt(s)>ans){
            ans = holeCnt(s);
            //cerr<<i<<"--"<<s<<endl;
        }
    }

    cout<<ans<<endl;
    

    return 0;
}