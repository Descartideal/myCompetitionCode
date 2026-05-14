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
    vector<int> a(n);for(int& x:a)cin>>x;
    int l,r;



    for(int i=0;i<n;++i){
        if(a[i]!=n-i){
            l = i;
            break;
        }
    }

    for(int i=l;i<n;++i){
        if(a[i]==n-l){
            r = i;
            break;
        }
    }

    vector<int> b(a.begin()+l,a.begin()+r+1);
 //   cerr<<l<<" "<<r<<" asdf:"<<b.size()<<endl;
    for(int i=0;i<l;++i){
        cout<<a[i]<<" ";
    }
    for(int i=b.size()-1;i>=0;--i){
        cout<<b[i]<<" ";
    }
    for(int i=r+1;i<n;++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
	return;





    function<void(int,vector<int>)> f;
    f = [&](int n, vector<int> a){
        int d;

        for(int i=0;i<n;++i){
            if(a[i]==n){
                d = i;
            }
        }

        if(d==0){
            cout<<a[0]<<" ";
            vector<int> b(a.begin()+1,a.end());
            f(n-1,b);
            return;
        }

        for(int i=d;i>=0;--i){
            cout<<a[i]<<" ";
        }
        if(d==n-1){
            cout<<endl;
            return;
        }

        for(int i=d+1;i<n;++i){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    };

    f(n,a);
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
