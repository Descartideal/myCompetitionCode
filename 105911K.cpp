#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> a(n+1,0);
    vector<int> b(4,0);
    vector<vector<int>> aa(4,vector<int>(n+1,0));
    vector<int> cntbb(4,0);
    int cntb = 0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    vector<int> ans(4,0);
    
    for(int i=0;i<4;++i){
        cntb = 0;
        for(int j=1;j<=n;++j){
            aa[i][j] = (a[j]+i)%4;
            ans[i] += aa[i][j];
            cntb += 3*aa[i][j];

            //cerr<<aa[i][j]<<" ";
        }//cerr<<endl;
        ans[i]+=((cntb+i)%4);
    }

    int cntbm = cntb%4;
/** 
    for(int i=0;i<4;++i){
        cerr<<ans[i]<<" ";
    }cerr<<endl;
*/
    cout<<*min_element(ans.begin(),ans.end())<<endl;

}