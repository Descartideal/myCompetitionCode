#include <bits/stdc++.h>
using namespace std;
vector<pair<double,double>> a(16);
vector<int> b(16);
double Min = 2147483647.0;

const int N=20;
const double T0=1e5;
const double T_end=1e-4;
const double D=1-3e-3;
const int L=80;
int n,st=clock();

double rand_f() {return double(rand())/double(RAND_MAX);}

double dis(pair<double,double> a,pair<double,double> b){
	return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

double run(vector<int> b){
	double sum = 0;
	sum += dis({0,0},a[b[1]]);
	for(int i=1;i<=n-1;++i){
		sum += dis(a[b[i]],a[b[i+1]]);
	}
	return sum;
}

bool RP_up(double delta,double t) {return delta>0||rand_f()<exp(delta/t);}

void SA() {
	for(int i=1;i<=n;++i)b[i]=i;
	double T=T0,sum=run(b);
	while(T>T_end) {
		for(int i=0;i<L;++i) {
			int u=rand()%n+1,v=rand()%n+1;
			swap(b[u],b[v]);
			double tsum=run(b);
			if(RP_up(sum-tsum,T)) sum=tsum,Min=min(Min,sum);
			else swap(b[u],b[v]);
		}T*=D;
	}
}

int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].first>>a[i].second;
	}

	while(clock()-st<0.92*CLOCKS_PER_SEC){
		SA();
		cerr<<"asdf";
	}
	printf("%.2f",Min);
	return 0;
}
