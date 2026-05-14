#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

using i64 = long long;
using ll =long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

const i64 MOD = 998244353;
vector<vector<i64>> C(101,vector<i64>(101,0));

void m(i64& x){
    x = x%MOD;
}


pair<i64,i64> calc_bad(const string& s, int n, const vector<vector<i64>>& C) {

    vector<i64> R(n,0);R[n-1] = 0;
    for(int i=n-2;i>=0;--i){
        if(s[i+1]==')'){
            R[i] = R[i+1]+1;
        }else{
            R[i] = R[i+1];
        }
    }

    i64 cntBad = 0;
    i64 sumLenBad = 0;

    for (int k=0;k<n;++k) {
        if(s[k] != '(')continue;

        vector<i64>A(n+1,0);
        A[0] = 1;
        vector<vector<i64>> B(n+1,vector<i64>(n+1,0));

        for(int i=0;i<k;++i) {
            if (s[i] == '(') {
                for (int a=n-1; a >= 0; --a) {
                    A[a + 1] += A[a];
                    if (A[a + 1] >= MOD) A[a + 1] -= MOD;
                }
            } else {
                for (int a = 0; a <= n; ++a) {
                    for (int h = 1; h <= n; ++h) {
                        if (B[a][h] == 0) continue;
                        B[a][h - 1] += B[a][h];
                        B[a][h - 1] %= MOD;
                    }
                }
                for (int a = 1; a <= n; ++a) {
                    if (A[a] == 0) continue;
                    B[a][a - 1] += A[a];
                    B[a][a - 1] %= MOD;
                }
            }
        }

        int rightClose = R[k];

        for (int a = 0; a <= n; ++a) {
            if (A[a] == 0) continue;
            int need = a + 1;
            if (need > rightClose) continue;

            i64 ways = A[a] * C[rightClose][need] % MOD;
            cntBad += ways;
            cntBad %= MOD;

            i64 len = (2LL * a + 2) % MOD;
            sumLenBad += ways * len % MOD;
            sumLenBad %= MOD;
        }

        for (int a = 0; a <= n; ++a) {
            for (int h = 0; h <= n; ++h) {
                i64 val = B[a][h];
                if (val == 0) continue;
                int need = h + 1;
                if (need > rightClose) continue;

                i64 ways = val * C[rightClose][need] % MOD;
                cntBad += ways;
                cntBad %= MOD;

                i64 len = (2LL * a + 2) % MOD;
                sumLenBad += ways * len % MOD;
                sumLenBad %= MOD;
            }
        }
    }

    return {cntBad, sumLenBad};
}


void solve(){
    int n;cin>>n;
    string s;cin>>s;
    i64 res = 0;

    vector<i64> cnt(n+1,0),lensum(n+1,0);cnt[0]=1;lensum[0]=0;
    for(char c:s){
        vector<i64> rcnt=cnt,rlensum=lensum;
        if(c=='('){
            for(int i=0;i<=n-1;++i){
                rcnt[i+1] += cnt[i];
                rlensum[i+1] += lensum[i]+cnt[i]; 
            }
        }else{
            for(int i=1;i<=n;++i){
                rcnt[i-1] += cnt[i];
                rlensum[i-1] += lensum[i]+cnt[i]; 
            }
        }
        for(int i=0;i<=n;++i){
            m(rcnt[i]);m(rlensum[i]);
        }
        cnt=rcnt;lensum=rlensum;
    }
    i64 Acnt = cnt[0]-1;
    i64 Alensum = lensum[0];

    
    auto [cntBad, sumLenBad] = calc_bad(s, n, C);

    i64 ans = 0;
    ans += Alensum;
    ans -= (2 * Acnt) % MOD;
    ans %= MOD;

    i64 badPart = 0;
    badPart += sumLenBad;
    badPart -= (2 * cntBad) % MOD;
    badPart %= MOD;

    ans -= badPart;
    ans %= MOD;

    if (ans < 0) ans += MOD;
    cout << ans << "\n";

	return;
}


int main(){
        
    C[0][0] = 1;
    for (int i = 1; i <= 100; ++i) {
        C[i][0] = 1;
        C[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            C[i][j] %= MOD;
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
