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
    vector<int> a(n+1,0);
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }

    vector<int> b(n+1,0);
    for(int i=1;i<=n-1;++i){
        b[i] = a[i+1]-a[i];
    }
    n = n-1;

    vector<int> last(n+2,0);

    i64 res = 0;
    for(int i=1;i<=n;++i){
        int& x=b[i],y=last[i];
        if(x<-1){
            if(y==0){
                int diff = -1-x;
                res += i*diff;
                x = -1;
            }else{
                int diff = -1-x;
                while (y!=0 && diff>0) {
                    while (b[y]!=-1 && diff>0) {
                        b[y]--;
                        x++;
                        diff--;
                        res += (i-y);
                    }
                    y = last[y];
                }
                if(diff>0){
                    res += i*diff;
                    x = -1;
                }else{
                    last[i+1] = y;
                }
            }
            continue;
        }
        if(x>1){
            int diff = x-1;
            res += diff;
            x=1;
            b[i+1] += diff;
            last[i+1] = i;
            continue;
        }
        if(x>-1){
            last[i+1] = i;
        }else{
            last[i+1] = y;
        }
    }

    cout<<res<<endl;
	return;
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
