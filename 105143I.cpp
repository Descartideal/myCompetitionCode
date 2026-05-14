#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;cin>>s;
    if(s[0]==0 && is_sorted(s.begin(),s.end())){
        cout<<0<<endl;
        return 0;
    }

    vector<int> ans;

    int cnt = 0 , state = 0;
    for(int i=0;i<s.size();++i){
        char c = s[i];
        if(state==0 && c=='1'){
            state = 1;
            continue;
        }

        if(state==1 && c=='0'){
            state=2;
            cnt++;
            continue;
        }

        if(state==2 && c=='1'){
            state = 1;
            continue;
        }
    }
    ans.push_back(cnt);

    cnt=0;state=0;
    for(int i=s.size()-1;i>=0;--i){
        char c = s[i];
        if(state==0 && c=='0'){
            state = 1;
            continue;
        }

        if(state==1 && c=='1'){
            state=2;
            cnt++;
            continue;
        }

        if(state==2 && c=='0'){
            state = 1;
            continue;
        }
    }
    ans.push_back(cnt);


    cout<<*min_element(ans.begin(),ans.end())<<endl;

    return 0;
}