#include <bits/stdc++.h>
using namespace std;

signed main(){
    int n;cin>>n;
    string s;cin>>s;
    s = ' '+s;
    int q;cin>>q;
    
    int limit = n/2+(n&1);
    vector<int> isOk(limit+1,0);

    int cnt = 0;
    for(int i=1;i<=limit;++i){
        if(s[i]==s[n-i+1]){
            isOk[i] = 1;
            cnt++;
        }
    }

    for(int i=1;i<=q;++i){
        int dex;char c;
        cin>>dex>>c;

        s[dex] = c;

        if(dex>limit)dex=n-dex+1;
        if(s[dex]==s[n-dex+1]){
            if(isOk[dex]){
                ;
            }else{
                isOk[dex] = 1;
                cnt++;
            }
        }else{
            if(isOk[dex]){
                isOk[dex] = 0;
                cnt--;
            }else{
                ;
            }
        }

        if(cnt==limit){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    
}