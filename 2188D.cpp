#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

using i64 = long long;
using ll =long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

using b32 = bitset<32>;
 

void solve(){
    u32 x,y;cin>>x>>y;
    b32 p(x),q(y);
    b32 diff = q&p;
    b32 empty = ~(q|p);
    
    int state = 0;
    vector<u32> com(4);
    //down
    b32 pd(p);
    for(int i=31;i>=0;--i){
        if(diff[i]==1){
            pd[i]=0;
            state = 1;
        }
        if(state==1 && empty[i]==1){
            pd[i]=1;
        }
    }
    com[0] = p.to_ulong()-pd.to_ulong();

    state=0;
    b32 qd(q);
    for(int i=31;i>=0;--i){
        if(diff[i]==1){
            qd[i]=0;
            state = 1;
        }
        if(state==1 && empty[i]==1){
            qd[i]=1;
        }
    }
    com[1] = q.to_ulong()-qd.to_ulong();


    //up
    b32 pu(p);
    for(int i=31;i>=0;--i){
        if(diff[i]==1){
            state = i;
            break;
        }
    }
    for(int i=state;i<32;++i){
        if(empty[i]==1){
            pu[i]=1;
            for(int j=i-1;j>=0;--j){
                pu[j]=0;
            }
            break;
        }
    }
    com[2] = pu.to_ulong()-p.to_ulong();

    b32 qu(q);
    for(int i=31;i>=0;--i){
        if(diff[i]==1){
            state = i;
            break;
        }
    }
    for(int i=state;i<32;++i){
        if(empty[i]==1){
            qu[i]=1;
            for(int j=i-1;j>=0;--j){
                qu[j]=0;
            }
            break;
        }
    }
    com[3] = qu.to_ulong()-q.to_ulong();

//    for(int i=0;i<4;++i){
//        cerr<<com[i]<<" ";
//    }cerr<<endl;



    int change = min_element(com.begin(),com.end())-com.begin();
    if(change==0){
        cout<<pd.to_ulong()<<" "<<q.to_ulong();
    }else if(change==1){
        cout<<p.to_ulong()<<" "<<qd.to_ulong();
    }else if(change==2){
        cout<<pu.to_ulong()<<" "<<q.to_ulong();
    }else{
        cout<<p.to_ulong()<<" "<<qu.to_ulong();
    }

    cout<<endl;
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
