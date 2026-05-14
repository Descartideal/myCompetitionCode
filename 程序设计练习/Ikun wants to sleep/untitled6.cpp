#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n;cin>>n;
	char a [n+1][2];
	for(int i=1;i<=n;++i){
		cin>>a[i][0]>>a[i][1];
	}
	vector<int> dp(26,INT_MAX);
	vector<vector<int>> b(n+1,vector<int>(2));
	b[1][0]=0;b[1][1]=0;
	for(int i=2;i<=n;++i){
		b[i][0] = max(b[i-1][0]+(a[i-1][1]==a[i][0]),b[i-1][1]+(a[i-1][0]==a[i][0]));
		b[i][1] = max(b[i-1][0]+(a[i-1][1]==a[i][1]),b[i-1][1]+(a[i-1][0]==a[i][1]));
	}
	cout<<2*n-max(b[n][0],b[n][1]);
	return 0;
}
