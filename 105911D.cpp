#include <bits/stdc++.h>
using namespace std;
const int maxn = 6e5 + 5;

struct line
{
    int x, y, z;
    int X, Y, Z;
} l[maxn];

bool cx(line A, line B) { return A.x < B.x; }
bool cy(line A, line B) { return A.y < B.y; }
bool cz(line A, line B) { return A.z < B.z; }

int lx[maxn], ly[maxn], lz[maxn];

int tox = 0, toy = 0, toz = 0;

struct tree
{
    int w[maxn * 4], lzy[maxn * 4], lzy2[maxn * 4], a[maxn];
    bool IR(int L, int R, int l, int r) { return (L <= l) && (r <= R); }
    bool OR(int L, int R, int l, int r) { return (r < L) || (l > R); }

    void m_tag(int u, int x, int op)
    {
        if (lzy[u] == maxn)
        {
            lzy2[u] += x;
        }
        else
        {
            lzy[u] += x;
        }
        w[u] += x;
    }

    void pushdown(int u)
    {
        if (lzy[u] == maxn)
        {
            m_tag(u * 2, lzy2[u], 2);
            m_tag(u * 2 + 1, lzy2[u], 2);
            lzy2[u] = 0;
        }
        else
        {
            m_tag(u * 2, lzy[u], 1);
            m_tag(u * 2 + 1, lzy[u], 1);
            lzy[u] = maxn;
        }
    }

    void pushup(int u) { w[u] = max(w[u * 2], w[u * 2 + 1]); }
    void build(int u, int l, int r)
    {
        if (l == r)
        {
            lzy[u] = maxn;
            w[u] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(u * 2, l, m);
        build(u * 2 + 1, m + 1, r);
        pushup(u);
        lzy[u] = maxn;
    }
    void update(int u, int L, int R, int l, int r, int x, int op)
    {
        


        if(l>r){
            swap(l, r);
        }
        if (IR(l, r, L, R))
        {
            m_tag(u, x, op);
        }
        else if (!OR(l, r, L, R))
        {
            int m = (L + R) / 2;
            pushdown(u);
            update(u * 2, L, m, l, r, x, op);
            update(u * 2 + 1, m + 1, R, l, r, x, op);
            pushup(u);
        }
    }
    int qu(int u, int L, int R, int l, int r)
    {
        if(l>r){
            swap(l, r);
        }
        if (IR(l, r, L, R))
        {
            return w[u];
        }
        else if (!OR(l, r, L, R))
        {
            int m = (L + R) / 2;
            pushdown(u);
            return max(qu(u * 2, L, m, l, r), qu(u * 2 + 1, m + 1, R, l, r));
        }
        else
        {
            return -1;
        }
    }
} tx, ty, tz;

signed main()
{

    int n, a, b, c;
    cin >> n >> a >> b >> c;
    memset(tx.a, 0, sizeof(tx.a));
    memset(ty.a, 0, sizeof(ty.a));
    memset(tz.a, 0, sizeof(tz.a));

    tx.build(1, 1, n);
    ty.build(1, 1, n);
    tz.build(1, 1, n);

    set<int> lsh;

    for (int i = 1; i <= n; i++)
    {
        cin >> l[i].x >> l[i].y >> l[i].z >> l[i].X >> l[i].Y >> l[i].Z;
        lsh.insert(l[i].x);
        lsh.insert(l[i].y);
        lsh.insert(l[i].z);
        lsh.insert(l[i].X);
        lsh.insert(l[i].Y);
        lsh.insert(l[i].Z);
    }

    //----------------------
    vector<int> lx, ly, lz;

    vector<int> ls(1, 0);
    for (int x : lsh)
    {
        ls.push_back(x);
    }

    for(int i=1;i<=ls.size()-1;++i){
        cerr<<ls[i]<<" ";
    }cerr<<endl;

    unordered_map<int, int> hs;
    for (int i = 1; i <= ls.size()-1; i++)
    {
        hs[ls[i]] = i;
    }

    //---------------------------

    for (int i = 1; i <= n; i++)
    {
        tx.update(1, 1, n, hs[l[i].x], hs[l[i].X], 1, 1);
        ty.update(1, 1, n, hs[l[i].y], hs[l[i].Y], 1, 1);
        tz.update(1, 1, n, hs[l[i].z], hs[l[i].Z], 1, 1);
    }

    int ansx = -1;
    int ansy = -1;
    int ansz = -1;
    for (int i = 1; i <= n; i++)
    {
        ansx = max(tx.qu(1, 1, n, hs[l[i].x], hs[l[i].X]), ansx);
        ansy = max(ty.qu(1, 1, n, hs[l[i].y], hs[l[i].Y]), ansy);
        ansz = max(tz.qu(1, 1, n, hs[l[i].z], hs[l[i].Z]), ansz);
    }

    cout << max(max(ansx, ansy), ansz);
}