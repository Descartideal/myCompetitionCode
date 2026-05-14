#include <bits/stdc++.h>
#define int long long
using namespace std;
struct edge
{
    int v, w;
    bool operator<(const edge &P) const
    {
        return P.w < w;
    }
};
const int maxn = 4000005;
vector<edge> a[maxn];
int d[maxn];
bool c[maxn];
int ma[2005][2005];
int LIMIT;
void add(int u, int v, int w)
{
    edge P;
    P.v = v, P.w = w;
    a[u].push_back(P);
    P.v = u;
    a[v].push_back(P);
}
void dijk(int s)
{
    for (int i = 0; i <= LIMIT; i++)
    {
        d[i] = LLONG_MAX;
        c[i] = true;
    }
    priority_queue<edge> q;
    d[s] = 0;
    edge p;
    p.v = s, p.w = 0;
    q.push(p);
    while (q.size())
    {
        int u = q.top().v;
        q.pop();
        if (!c[u])
        {
            continue;
        }
        c[u] = false;
        for (int i = 0; i < a[u].size(); i++)
        {
            int y = a[u][i].v, w = a[u][i].w;
            if (d[u] + w < d[y])
            {
                d[y] = d[u] + w;
                p.v = y, p.w = d[y];
                q.push(p);
            }
        }
    }
}
int an[20][20];
int dp[15][1 << 15];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, c, k;
        cin >> n >> m >> c >> k;
        LIMIT = n * m;
        for (int i = 0; i <= LIMIT; i++)
        {
            a[i].clear();
        }
        vector<int> C;
        int x, y;
        cin >> x >> y;
        int s = y + ((x - 1) * m);
        for (int i = 1; i <= n; i++)
        {
            string s;
            cin >> s;
            for (int j = 1; j <= m; j++)
            {
                ma[i][j] = s[j - 1] - '0';
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (ma[i][j] == 2)
                {
                    continue;
                }
                if (j > 1 && ma[i][j - 1] != 2)
                {
                    add(j + (i - 1) * m, (j - 1) + (i - 1) * m, max(ma[i][j], ma[i][j - 1]));
                }
                if (i > 1 && ma[i - 1][j] != 2)
                {
                    add(j + (i - 1) * m, j + (i - 2) * m, max(ma[i][j], ma[i - 1][j]));
                }
            }
        }
        for (int i = 1; i <= c; i++)
        {
            int x, y;
            cin >> x >> y;
            C.push_back(y + (x - 1) * m);
        }
        int ans = LLONG_MAX;
        dijk(s);
        for (int i = 0; i < C.size(); i++)
        {
            an[0][i] = d[C[i]];
        }
        for (int i = 0; i < C.size(); i++)
        {
            dijk(C[i]);
            for (int j = 0; j < C.size(); j++)
            {
                an[i + 1][j] = d[C[j]];
            }
        }
        for (int M = 0; M < (1 << C.size()); M++)
        {
            for (int i = 0; i < C.size(); i++)
            {
                dp[i][M] = LLONG_MAX;
            }
        }
        for (int i = 0; i < C.size(); i++)
        {
            if (an[0][i] != LLONG_MAX)
            {
                dp[i][1 << i] = an[0][i];
            }
        }

        
        for (int M = 1; M < (1 << C.size()); M++)
        {
            for (int i = 0; i < C.size(); i++)
            {
                if (!(M & (1 << i)) || dp[M][i] == LLONG_MAX)
                    continue;
                for (int j = 0; j < C.size(); j++)
                {
                    if (M & (1 << j))
                        continue;
                    if (an[i + 1][j] == LLONG_MAX)
                        continue;
                    int nM = M | (1 << j);
                    dp[j][nM] = min(dp[j][nM], dp[i][M] + an[i + 1][j]);
                }
            }
        }
        int Ans = LLONG_MAX;
        for (int M = 0; M < (1 << C.size()); M++)
        {
            if (__builtin_popcount(M) >= k)
            {
                for (int i = 0; i < C.size(); i++)
                {
                    Ans = min(Ans, dp[i][M]);
                }
            }
        }
        if (Ans == LLONG_MAX)
        {

            cout << -1 << "\n";
        }
        else
        {
            cout << Ans << "\n";
        }
    }
}