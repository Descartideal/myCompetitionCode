#include <bits/stdc++.h>
using namespace std;

#ifdef __unix__
#define gc getchar_unlocked
#else
#define gc _getchar_nolock
#endif

int readint(){
    int k=0,f=1,c=gc();
    for(;!isdigit(c);c=gc())if(c=='-')f=-1;
    for(;isdigit(c);c=gc())k=10*k+(c&15);
    return k*f;
}

struct point
{
    bitset<5000> a;
    bitset<5000> b;
    int n;
    int id;
};
bool cmp(const point &A, const point &B)
{
    return A.n > B.n;
}
point a[5001];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char s = getchar();
            a[i].a[j - 1] = s - '0';
        }
        a[i].id = i;
    }
    for (int i = 1; i <= n; i++)
    {
        a[i].b = a[i].a;
        for (int j = 1; j <= n; j++)
        {
            if (a[i].a[j - 1])
            {
                a[i].b = a[i].b | a[j].a;
            }
        }
        a[i].n = a[i].b.count();
    }

    sort(a + 1, a + n + 1, cmp);

    int ans[4];
    int top = 0;
    for (int i = 1; i <= 3; i++)
    {
        if (a[i].n == n - 1)
        {
            ans[top++] = a[i].id;
        }
    }

    if (top < 3)
    {
        cout << "NOT FOUND";
    }
    else
    {
        cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];
    }
}