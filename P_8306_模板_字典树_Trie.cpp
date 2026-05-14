#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3000005;
const int SIGMA = 62;

int trie[MAXN][SIGMA];
int cnt[MAXN];
int tot;

int id(char c){
    if('a'<=c && c<='z')return c-'a';;
    if('A'<=c && c<='Z')return c-'A'+26;
    return c-'0'+52;
}

int new_node(){
    ++tot;
    cnt[tot] = 0;
    for(int i=0;i<SIGMA;++i)trie[tot][i] = 0;
    return tot;
}

void init(){
    tot = 0;
    cnt[0] = 0;
    for(int i=0;i<SIGMA;++i)trie[0][i] = 0;
}

void insert_string(const string& s){
    int u = 0;
    for(char ch:s){
        int c = id(ch);
        if(!trie[u][c])trie[u][c] = new_node();
        u = trie[u][c];
        cnt[u]++;
    }
}

int query(const string& s){
    int u = 0;
    for(char ch:s){
        int c = id(ch);
        if(!trie[u][c])return 0;
        u = trie[u][c];
    }
    return cnt[u];
}

void solve(){
    int n,q;cin>>n>>q;

    string s;
    for(int i=1;i<=n;++i){
        cin>>s;
        insert_string(s);
    }
    for(int i=1;i<=q;++i){
        cin>>s;
        cout<<query(s)<<'\n';
    }

    return;
}



signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;

    while(t--){
        init();
        solve();
    }

    return 0;
}