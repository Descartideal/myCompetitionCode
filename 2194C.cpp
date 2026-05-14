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
    int n,k; cin>>n>>k;
    vector<string> a(k);
    for(int i=0;i<k;i++)cin>>a[i];
    
    for(int d=1; d<=n; d++){
        if(n % d)continue;
        bool ok = 1;
        vector<char> t(d);
        for(int pos=0; pos<d; pos++){
            int mask = (1<<26)-1;
            for(int i=pos;i<n;i+=d){
                int cur = 0;
                for(int r=0;r<k;r++){
                    cur|=1<<(a[r][i]-'a');
                }
                mask&=cur;
            }
            if(mask == 0){
                ok = false;
                break;
            }
            t[pos]=__builtin_ctz(mask)+'a';
        }
        if(ok){
            for(int i=0;i<n;i++){
                cout << t[i % d];
            }
            cout<<endl;
            return;
        }
    }
}


int main(){
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
