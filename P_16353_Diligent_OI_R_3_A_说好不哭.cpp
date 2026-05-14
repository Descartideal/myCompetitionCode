#include <bits/stdc++.h>
using namespace std;
#define int long long

bool right(int n,int x,int y)
{
    if(x==y)   
    {
        if(x==0 && y==0 || n==1)    return true;
        else if(n!=1)   return false;
    }
    else if(n==1)
    {
        if(x!=y)    return false;
        else return true;
    }  
    else if(x>0&&y>0)  
    {
        int temp = (x-y)/(n-1);
        if(temp < y)    return false;
    }
    else if(x<0&&y<0)
    {
        long long temp = x*n;
        if(temp<y)  return false;
    }
    return true;
}
signed main()
{
    int T;  cin>>T;
    while(T--)
    {
        int n,y,x;
        cin>>n>>x>>y;
        if(right(n,x,y))    cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}