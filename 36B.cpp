#include<bits/stdc++.h>
using namespace std;

signed main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    int n,k;
    cin>>n>>k;

    vector<string>a(n+1);
    for(int i=1;i<=n;++i){
        string s;
        cin>>s;
        a[i]=" "+s;
    }

    int N=1;
    for(int i=1;i<=k;++i)N*=n;

    int p=1;
    for(int i=1;i<k;++i)p*=n;

    string row;
    row.reserve(N);

    for(int i=1;i<=N;++i){
        row.clear();
        for(int j=1;j<=N;++j){
            int x=i,y=j;
            int cur=p;
            bool black=false;

            for(int step=1;step<=k;++step){
                int r,c;
                if(cur==0){
                    r=c=1;
                }else{
                    r=(x-1)/cur+1;
                    c=(y-1)/cur+1;
                }

                if(a[r][c]=='*'){
                    black=true;
                    break;
                }

                if(cur==0)break;
                x=(x-1)%cur+1;
                y=(y-1)%cur+1;
                cur/=n;
            }

            row+=(black?'*':'.');
        }
        cout<<row<<'\n';
    }

    return 0;
}