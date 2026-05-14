#include <bits/stdc++.h>
using namespace std;

bool compare(string a,string b){
	return a<b;
}

bool com(tuple<int,string,int> a,tuple<int,string,int> b){
	auto [x1,x2,x3] = a;
	auto [y1,y2,y3] = b;
	return compare(x2,y2);
}

int main(){
	int n;cin>>n;
	vector<string> a(n);
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	
	vector<vector<tuple<int,string,int>>> g(26);
	vector<int> ru(26,0),chu(26,0);
	vector<int> g_consume(26,0);
	
	for(int i=0;i<n;++i){
		int s=a[i][0]-'a',t=a[i].back()-'a';
		++ru[t];++chu[s];
		g[s].push_back({t,a[i],0});
	}
	for(int i=0;i<26;++i){
		sort(g[i].begin(),g[i].end(),com);
	}
	
	vector<int> delta(26);
	int wrong = 0;stack<int> w_i;
	for(int i=0;i<26;++i){
		delta[i] = ru[i]-chu[i];
		if(delta[i]!=0){
			++wrong;
			if(abs(delta[i])>1){
				cout<<"***"<<endl;
				return 0;
			}
			w_i.push(i);
		}
	}
	if(wrong>2){
		cout<<"***"<<endl;
		return 0;
	}
	
	stack<int> point;
	stack<string> edge;
	stack<string> ans;
	
	if(wrong==0){
		for(int i=0;i<26;++i){
			if(ru[i]!=0){
				point.push(i);
				break;
			}
		}
	}
	
	if(wrong==2){
		while(1){
			int x = w_i.top();w_i.pop();
			if(delta[x]==-1){
				point.push(x);
				break;
			}
		}
	}
	
	int check=0;
	while(!point.empty()){
		int x = point.top();
		if(chu[x]==g_consume[x]){
			if(!edge.empty()){
				ans.push(edge.top());edge.pop();
				++check;
			}
			point.pop();
			continue;
		}
		int y = g_consume[x];++g_consume[x];
		auto& [g1,g2,g3] = g[x][y];
		point.push(g1);edge.push(g2);g3 = 1;
	}
	
	if(check!=n){
		cout<<"***"<<endl;
		return 0;
	}
	
	while(1){
		string s = ans.top();ans.pop();
		cout<<s;
		if(!ans.empty()){
			cout<<".";	
		}else{
			break;
		}
	}
	
	return 0;
}
