#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

using i64 = long long;
using ll =long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;


void solve(){
    int n;cin>>n;
    int pm = (2<<n)-1 , pmr;
    srand(time(0));
    vector<vector<int>> a(n+1,vector<int>(n+1,-1));
    vector<vector<int>> q(pm+1);

    function<void(int)> qs;
    qs = [&](int x){
        cout<<'?'<<" "<<x<<endl;
        int ct;cin>>ct;q[x].push_back(ct);
        if(ct==0)return;
        for(int i=1;i<=ct;++i){
            int y;cin>>y;q[x].push_back(y);
            if(i>1){
                a[ q[x][i-1] ][ q[x][i] ] = 1;
            }
            for(int j=i-1;j>=1;--j){
                a[ q[x][i] ][ q[x][j] ] = 0;
            }
        }
    };

    int l=1,r=pm;
    while (l<r){
        int mid = ((l+r)>>1);
        if(l+1==r){
            mid = r;
        }
        qs(mid);
        if(q[mid][0]==0){
            r = mid-1;
        }else{
            l = mid;
        }
    }
    pmr = l;

    vector<int> head(n+1,0);

    auto ck = [&](){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(a[i][j]==-1){
                    return pii{i,j};
                }
            }
        }
        return pii{0,0};
    };

    while(1){
        int x = rand()%pmr + 1;
        if(q[x].size()!=0)continue;
        qs(x);
        if(ck()==pii{0,0}){
            break;
        }
    }

    vector<pair<int,int>> edges;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j] == 1)edges.push_back({i,j});
        }
    }

    cout<<"! "<<edges.size()<<endl;
    for(auto [u,v]: edges){
        cout<<u<<" "<<v<<endl;
    }
    cout.flush();
	return;
}


signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
	int t;cin>>t;
	while(t-->0){
		solve();
	}
	return 0;
}


















/*
***** Orz  Kiropo *******
*　　┏┓　　　┏┓+ +
*　┏┛┻━━━┛┻┓ + +
*　┃　　　　　　　┃
*　┃　　　━　　　┃ ++ + + +
*  ████━████+
*  ◥██◤　◥██◤ +
*　┃　　　┻　　　┃
*　┃　　　　　　　┃ + +
*　┗━┓　　　┏━┛
*　　　┃　　　┃ + + + +Code is far away from 　
*　　　┃　　　┃ + bug with the animal protecting
*　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
*　　　┃ 　　　　　　 ┣┓
*　　  ┃ 　　　　　 　┏┛
*　    ┗┓┓┏━┳┓┏┛ + + + +
*　　　　┃┫┫　┃┫┫
*　　　　┗┻┛　┗┻┛+ + + +
*/

//————自由是遗忘的左伴随
