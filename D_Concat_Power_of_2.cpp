#include <bits/stdc++.h>
using namespace std;

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v)os<<x<<" ";
    return os;
}

signed main(){
    int n;cin>>n;
    vector<vector<string>> g(10);
    vector<int> a(30,1);
    for(int i=1;i<30;++i){
        a[i] = a[i-1]<<1;
    }

    vector<string> ans(1,"0");
    //function<void(int,vector<string>&)> f;


    for(int len=1;len<=9;++len){
        vector<string> temp;
        for(int i=0;i<30;++i){
            string s = to_string(a[i]);
            int x = s.size();
            int y = len - x;
            if(y<0)break;
            if(y==0){
                temp.push_back(s);
                continue;
            }
            for(auto t:g[y]){
                temp.push_back(s+t);
            }
        }
        sort(temp.begin(),temp.end());
        temp.erase(unique(temp.begin(),temp.end()),temp.end());
        g[len] = temp;
        for(auto s:temp){
            ans.push_back(s);
        }
    }
    cout<<ans[n]<<endl;

    return 0;
}