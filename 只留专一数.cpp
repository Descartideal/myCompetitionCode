#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

using i64 = long long;
using ll =long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

vector<int> p;
int z[1010];

void solve(){
    int n;cin>>n;
    vector<int> a(n);for(int& x:a)cin>>x;
    bool j = 0;
    for(int& x:a){
        if(z[x]==1){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;

	return;
}


int main(){
    vector<int> pj(1001,1);
    pj[1]=0;
    pj[0]=0;
    for(int i=2;i<=1000;++i){
        for(int& x:p){
            if(i%x==0){
                pj[i]=0;
                break;
            }
            if(x>sqrt(i)+1){
                break;
            }
        }
        if(pj[i]==1){
            p.push_back(i);
        }
    }

    for(int i=1;i<=1000;++i){
        int y = i;
        set<int> t;
        for(int& x:p){
            while(y%x==0){
                y/=x;
                t.insert(x);
            }
            if(x>y)break;
        }
        if(t.size()>1){
            z[i]=0;
        }else{
            z[i]=1;
        }
    }

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
