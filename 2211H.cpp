#include <bits/stdc++.h>
using namespace std;
//using i128 = __int128;
using ll = long long;

#define int long long

struct vec{
    int x,y;
};

vec operator-(vec a,vec b){
    vec c;
    c.x = a.x-b.x;
    c.y = a.y-b.y;
    return c;
}

int operator*(vec a,vec b){
    return a.x*b.x+a.y*b.y;
}

bool operator==(vec a,vec b){
    if(a.x==b.x && a.y==b.y){
        return true;
    }else{
        return false;
    }
}
/** 
int abs(int x){
    if(x<0){
        return -x;
    }
    return x;
}*/

int mhash(vec a){
    if(a.x==0){
        a.y = abs(a.y);
    }
    if(a.y==0){
        a.x = abs(a.x);
    }
    if(a.x<0){
        a.x = -a.x;
        a.y = -a.y;
    }

    return (a.x)*1e9+a.y;
}

struct V{
    vec v;
    int i,j;
};

void solve(){
    ll nn;
    int n;cin>>nn;
    n = nn;
    vector<vec> a(n+1);

    unordered_map< int,vector<V> > t;

    for(int i=1;i<=n;++i){
        ll tx,ty;
        cin>>tx>>ty;
        a[i].x=tx;
        a[i].y=ty;
    }

    for(int i=1;i<=n-1;++i){
        for(int j=i+1;j<=n;++j){
            V temp;
            temp.v = (a[i]-a[j]);
            temp.i = i;
            temp.j = j;
            t[mhash(a[i]-a[j])].push_back(temp);
        }
    }

    

    ll ans = 0;

    for(auto [A,B]:t){
        int m = B.size();
        if(m<=1)continue;

        for(int i=0;i<m-1;++i){
            for(int j=i+1;j<m;++j){
                set<int> uni;
                uni.insert(B[i].i);
                uni.insert(B[i].j);
                uni.insert(B[j].i);
                uni.insert(B[j].j);
                if(uni.size()!=4)continue;

                int eg1,eg2;
                if(B[i].v==B[j].v){
                    eg1 = B[i].i;
                    eg2 = B[j].i;
                }else{
                    //cerr<<"asd "<<i<<" "<<j<<endl;
                    eg1 = B[i].i;
                    eg2 = B[j].j;//cerr<<eg2<<endl;
                }

                if( (a[eg1]-a[eg2])*B[i].v!=0 )continue;


                unordered_map<int,int> point;
                for(auto x:uni){
                    point[x] = 1;
                }

                for(int k=1;k<=n;++k){
                    if(point[k]==1)continue;
                    

                    vec judg = a[ eg1 ]-a[ eg2 ];
                    vec rejudg = a[ eg2 ]-a[ eg1 ];

                    vec de = a[eg1] - a[k] ;
                    vec ae = a[eg2]-a[k];



                    //cerr<<"asdf"<<m<<" "<<k<<endl;

                    if( (judg*de<0 || rejudg*ae<0) && (a[k]-a[B[i].i])*B[i].v ==  (a[B[i].j]-a[k])*B[i].v ){
                        //cerr<<"ans:"<<B[i].i<<" "<<B[i].j<<" "<<B[j].i<<" "<<B[j].j<<" "<<k<<endl;
                        ans++;
                    }
                }
            }
        }
    }

    cout<<ans<<endl;
    return;
}

signed main(){
        solve();
    
}
