#include <bits/stdc++.h>
using namespace std;

#define int long long

int sg[1010] = {
    0,
    1, 2, 1, 4, 3,
    2, 1, 5, 6, 2,
    1, 8, 7, 5, 9,
    8, 7, 3, 4, 7,
    4, 2, 1, 10, 9,
    3, 6, 11, 12
};
int b[1010];

int SG(int x){
    return sg[x];
}

signed main(){
    /** 
    sg[0]=0;
    sg[1]=1;
    sg[2]=2;
    sg[3]=1;
    sg[4]=2;
    sg[5]=3;
    int b[100] = {0,0,1,2,0,2};
    for(int i=6;i<=40;++i){
        vector<int>t;
        for(int j=2;j<=i-1;++j){
            if(i%j==0){
                ;
            }else{
                b[j] ^= 1;
            }
        }
        b[i] = sg[i-1];
        for(int j=1;j<=i;++j){
            t.push_back(b[j]);
        }
        sort(t.begin(),t.end());
        int cnt = 0;
        for(int x:t){
            if(cnt==x)cnt++;
        }
        sg[i] = cnt;
    }
*/
/** 
    for(int i=1;i<=30;++i){
        cerr<<sg[i]<<endl;
    }
*/
    int n;cin>>n;
    int limit = sqrt(n)+1;
    if(n==1){
        cout<<"Vasya"<<endl;
        return 0;
    }
    if(n==2){
        cout<<"Petya"<<endl;
        return 0;
    }

    int xr = 0;

    int cnt1 = n-limit;
    vector<int> vis(limit+1,0);
    
    cnt1++;
    for(int i=2;i<=limit;++i){
        if(vis[i])continue;
        int x = i;
        int y = 1;
        while(1){
            if(x<=limit)vis[x] = 1;
            x*=i;
            if(x>n)break;
            if(x>limit)cnt1--;
            y++;
        }
        xr ^= SG(y);
    }
    xr ^= (cnt1&1);
    if(xr){
        cout<<"Vasya"<<endl;
    }else{
        cout<<"Petya"<<endl;
    }
    return 0;
}