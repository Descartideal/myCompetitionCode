#include <bits/stdc++.h>
using namespace std;
int n,m;    
long long sum[100010];
bool judge(int mid)
{
    int cnt = 0;
    int poi1=1;
    while(poi1<=n)
    {
        int poi2=poi1;
        while(poi2<=n)
        {
            int cur = sum[poi2]-sum[poi1-1];
            if(cur<=mid)    poi2++;
            else break;
        }
        if(poi1==poi2)  return false;
        poi1=poi2;
        cnt++;
        if(cnt>m)   return false;
    }
    if(poi1<n)  cnt++;
    if(cnt<=m)  return true;
    return false;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)  
    {
        int temp;
        scanf("%d",&temp);
        sum[i] = sum[i-1]+temp;
    } 
    int l=1,r=1e9+10;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(judge(mid))  r=mid-1;      //可以达到
        else l=mid+1;
    }
    cout<<r+1;
}