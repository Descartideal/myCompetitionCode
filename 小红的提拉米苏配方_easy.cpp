#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

using i64 = long long;
using ll = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve(){
    string s;cin>>s;
    int n=(int)s.size();
    vector<int> pos;
    pos.reserve(n);
    for(int i=0;i<n;i++) if(s[i]=='1') pos.push_back(i);
    int k=(int)pos.size();
    if(k<=1){
        cout<<s<<"\n";
        return;
    }
    int op=k/2;
    if(k%2==0){
        vector<char> del(n,0);
        for(int i=0;i<op;i++) del[pos[i]]=1;
        string ans;
        ans.reserve(n-op);
        for(int i=0;i<n;i++){
            if(del[i]) continue;
            char c=s[i];
            if(c=='1') c='2';
            ans.push_back(c);
        }
        cout<<ans<<"\n";
        return;
    }

    int P=pos[op];

    string B;
    B.reserve(P+1);
    vector<int> ins(op+1);
    int j=0;
    for(int i=0;i<=P;i++){
        if(j<=op && i==pos[j]){
            ins[j]=(int)B.size();
            j++;
        }else{
            if(s[i]!='1') B.push_back(s[i]);
        }
    }

    int keep=0;
    for(int t=1;t<=op;t++){
        int p=ins[keep];
        if(p<(int)B.size() && B[p]=='0') keep=t;
        else break;
    }

    string ans;
    ans.reserve(n-op);
    int p=ins[keep];
    ans.append(B.begin(),B.begin()+p);
    ans.push_back('1');
    ans.append(B.begin()+p,B.end());

    for(int i=P+1;i<n;i++){
        char c=s[i];
        if(c=='1') c='2';
        ans.push_back(c);
    }

    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr); cerr.tie(nullptr);
    solve();
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
