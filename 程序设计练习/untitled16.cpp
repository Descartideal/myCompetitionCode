#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	vector b(n+1,0);
	vector c(n+1,0);
	int mi = 2147483647;
	for(int i=1;i<=n;++i){
		if(b[i] == 0){
			int j=i;
			int sign = i;
			int k=0;
			while(1){
				k++;
				if(b[j]==0){
					b[j]=k;
					c[j]=sign;
				}else{
					if(c[j]==sign){
						int t = k-b[j];
						mi = min(t,mi);
						break;
					}else{
						break;
					}
				}
				j = a[j];
			}
		}
	}
	cout<<mi<<endl;
	
	return 0;
}
