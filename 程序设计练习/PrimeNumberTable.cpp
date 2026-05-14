#include <bits/stdc++.h>
using namespace std;
const int MAX=50000;

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int a[MAX]={0};
	a[0]=2;a[1]=2;
	for(int i=2;i<=sqrt(MAX)+1;i++){
		if(a[i]==0){
			int j=i;
			while(j<MAX){
				j+=i;
				a[j]=2;
			}
		}
	}
	int sum=0;
	int count=0;
	for(int i=2;i<MAX;i++){
		
		//if(i>1000)break;
		if(a[i]==0){
			sum+=i;
			cout<<i<<",";
			count++;
		}
	}
	cout<<endl<<count<<endl;
	
	return 0;
}
