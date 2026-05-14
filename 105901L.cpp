#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int ans=-1;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if((arr[i]+arr[j])&1)continue;
            int mid=(arr[i]+arr[j])>>1;
            int pre=lower_bound(arr.begin()+i,arr.begin()+j+1,mid)-(arr.begin()+i);
            int at=upper_bound(arr.begin()+i,arr.begin()+j+1,mid)-lower_bound(arr.begin()+i,arr.begin()+j+1,mid);
            int aft=(j-i+1)-pre-at;
            if(at==0)continue;
            //
            at--;
            int cans=1;
            //cans=1;
            int del=max(pre,aft)-min(aft,pre);
            if(at>=del){
                cans=j-i+1;
            }
            else{
                // if(pre<aft){
                //     pre+=at;
                // }
                // else aft+=at;
                if(aft==pre+1){
                    cans=j-i+1;
                }
                else if(aft<pre+1){
                    cans+=aft*2;
                }
                else{
                    cans+=pre+pre+1;
                }
            }
            ans=max(ans,cans);
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}