#include <bits/stdc++.h>
using namespace std;

#define int long long

using pii = pair<int ,int >;

const int N = 1e6+10;

vector<int> a(N,0);

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v)os<<x<<" ";
    return os;
}


int solve2(string s){
    //cerr<<s<<endl;
    int n = s.size();

    vector<pii> a(n,{0,0});

    int cnt = 0;
    for(int i = 0;i<n-1;++i){
        if(s[i] == s[i+1]){
            if(a[i].first==0 && a[i].second==0){
                cnt++;
                a[i] = a[i+1] = {cnt,i};
            }else{
                a[i+1] = a[i];
            }
        }
    }

    vector<int> b(n,0);
    for(int i=0;i<n;++i){
        b[ a[i].first ]++;
    }

    int ans = 0;
    for(int i=1;i<=cnt;++i){
        ans += (b[i]/2);
    }

    return ans;
}




void solve(){
    string ss;cin>>ss;
    string s = ss+ss;

    

    int n = s.size();

    vector<pii> a(n,{0,0});

    int cnt = 0;
    for(int i = 0;i<n-1;++i){
        if(s[i] == s[i+1]){
            if(a[i].first==0 && a[i].second==0){
                cnt++;
                a[i] = a[i+1] = {cnt,i};
            }else{
                a[i+1] = a[i];
            }
        }
    }

   

    vector<int> b(n,0);
    for(int i=0;i<n;++i){
        b[ a[i].first ]++;
    }

    int jj=0;
    if(a[0].first>0){
        if(cnt>0 && s[0]==s.back()){
            int c = s[0];
            int cc = 0;
            for(int i=s.size()-1;i>=0;--i){
                if(s[i]==s[0]){
                    cc++;
                }else{
                    break;
                }
            }

            //cerr<<"cc: "<<cc<<" "<<b[1]<<endl;
            
            if(cc==1){
                b[1] += cc;
                if((b[1]%2==0) && (cc&1)){
                    jj=1;
                }
            }else{
                int t = b[1]+b[cnt];
                b[1] = b[cnt] = t;
                if((b[1]%2==0) && (cc&1)){
                    jj=1;
                }
            }
        }
    }
    
    /** 

    for(int i=0;i<n;++i){
        cerr<<a[i].first<<" ";
    }cerr<<endl;

    cerr<<s<<endl;
    cerr<<b<<endl;
*/

    n = n/2;
    if(b[0]==0 && cnt==1){
        cout<<n/2<<endl;
        return;
    }

    int j = 0;
    int state = 0;
    

    for(int i=1;i<=cnt;++i){
        if(b[i]%2==0){
            j=1;
            state = i;
            break;
        }
    }
    


    int res = 0;
    if(j==0){
        res = solve2(ss);
    }else{
        int pos = 0;
        for(int i=0;i<n;++i){
            if(a[i].first == state ){
                pos = i;
                break;
            }
        }

        //cerr<<"adsf "<<s.substr(pos+1-jj,n)<<endl;
        //cerr<<jj<<" "<<pos<<endl;

        res = solve2( s.substr(pos+1-jj,n) );
    }

    cout<<res<<endl;
    return;
}





signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);


    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}