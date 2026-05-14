#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define d(x) cerr<<"#---"<<#x<<"=="<<x<<endl;

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v)os<<x<<" ";
    os<<endl;
    return os;
}

#ifdef __unix__
#define gc getchar_unlocked
#else
#define gc _getchar_nolock
#endif

const int INF = 1e9+7;

int readint(){
    int k=0,f=1,c=gc();
    for(;!isdigit(c);c=gc())if(c=='-')f=-1;
    for(;isdigit(c);c=gc())k=10*k+(c&15);
    return k*f;
}

struct point{
    int i,j,d;
};

int di[4] = {-1,0,1,0}, dj[4] = {0,1,0,-1};

void solve(){
    int n;cin>>n;
    if(n==2){
        cout<<"1 2\n";
        return;
    }
    if(n==3){
        cout<<"1 2\n";
        cout<<"2 3\n";
        return;
    }
    if(n==4){
        cout<<-1<<endl;
        return;
    }

    int s = n%3;
    int cnt = 1;
    int tail = (n+1)/3;

    if(s==0){
        int l = n-tail-1;
        for(int i=1;i<=l;++i){
            cout<<i<<" "<<i+1<<"\n";
            cnt++;
        }
        for(int i=1;i<=tail;++i){
            cnt++;
            cout<<1<<" "<<cnt<<'\n';
        }
    }else if(s==1){
        n--;

        int l = n-tail-1;
        for(int i=1;i<=l;++i){
            cout<<i<<" "<<i+1<<"\n";
            cnt++;
        }
        for(int i=1;i<=tail;++i){
            cnt++;
            cout<<1<<" "<<cnt<<'\n';
        }

        n++;
        
        cnt++;
        cout<<2<<" "<<cnt<<"\n";

    }else{
        int l = n-tail-1;
        for(int i=1;i<=l;++i){
            cout<<i<<" "<<i+1<<"\n";
            cnt++;
        }
        for(int i=1;i<=tail;++i){
            cnt++;
            cout<<1<<" "<<cnt<<'\n';
        }
    }

    return;
}


signed main(){
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}