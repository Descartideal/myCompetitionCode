#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(){
	int n,l,r;cin>>n>>l>>r;
	vector<int> a(n+1);for(int& x:a)cin>>x;
	
	vector<int> dp(n+1,-INF);dp[0] = 0;
	
	deque<int> q;
	
	for(int i=l;i<=n;++i){
		while(!q.empty()){
			if(a[i]>q.back()){
				q.pop_back();
			}else{
				break;
			}
		}
		q.push_back(a[i]);
		
		if(i>r){
			;
		}
	}

	
	
	return 0;
}
