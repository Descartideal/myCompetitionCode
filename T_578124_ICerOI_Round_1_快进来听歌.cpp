#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int q;cin>>q;
    int ans=0;
    for(int ii=1;ii<=q;++ii){
        ll n,k;cin>>n>>k;
        vector<int> a(n+1,0);

        ll v=1LL<<(n-1);
        if(v<k){
            continue;
        }

        if(v==k){
            ans++;
            continue;
        }

        int cnt=0;
        while(k){
            a[cnt] = k&1;
            k>>=1;
            cnt++;
        }

        int cnt1 = 0;
        for(int i=0;i<n;++i){
            if(a[i]==1){
                cnt1++;
            }
        }

        if(cnt1<2){
            continue;
        }

        int limit = 0;
        int loop = 100;
        while(loop--){
            if(cnt1==2 && a[n-1]==0){
                ans++;
                break;
            }
            if(cnt1==1 && a[n-1]==1){
                ans++;
                break;
            }

            

            int x=-1,y=-1,z=-1;
            for(int i=limit;i<n;++i){
                if(a[i]==1){
                    x=i;
                    break;
                }
            }
            for(int i=x+1;i<n;++i){
                if(a[i]==1){
                    y=i;
                    break;
                }
            }
            for(int i=y+1;i<n;++i){
                if(a[i]==0){
                    z=i;
                    break;
                }
            }

            if(z==-1 || y==-1 || x==-1){
                break;
            }else{
                a[x]=0;a[y]=0;
                a[z]=1;
                cnt1--;limit=y;
            }
        }

    }
    cout<<ans<<endl;
    return 0;
}