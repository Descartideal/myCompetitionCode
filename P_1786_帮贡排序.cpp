#include <bits/stdc++.h>
using namespace std;

struct info{
    string name,position;
    int contribution,rank,dex;
};

template<class T>
ostream& operator<<(ostream& os,vector<T>& v){
    for(const auto& x:v)os<<x;
    return os;
}


int main(){
    int n;cin>>n;
    vector<info> a(n);
    map<string,int> level = {{"BangZhu",0},{"FuBangZhu",1},{"HuFa",2},{"ZhangLao",3},{"TangZhu",4},{"JingYing",5},{"BangZhong",6}};

    int cnt = 0;
    for(auto& x:a){
        cin>>x.name>>x.position>>x.contribution>>x.rank;
        x.dex = cnt++;
    }
    
    sort(a.begin(),a.end(),[&](auto A,auto B){
        return level[A.position]<level[B.position];
    });

    
    auto b = a;
    sort(b.begin()+3,b.end(),[&](auto A,auto B){
        if(A.contribution==B.contribution){
            return A.dex<B.dex;
        }else{
            return A.contribution>B.contribution;
        }
    });

    


    vector<string> posi(200);
    for(int i=3;i<=4;++i){
        posi[i] = "HuFa";
    }
    for(int i=5;i<=8;++i){
        posi[i] = "ZhangLao";
    }
    for(int i=9;i<=15;++i){
        posi[i] = "TangZhu";
    }
    for(int i=16;i<=40;++i){
        posi[i] = "JingYing";
    }
    for(int i=41;i<=199;++i){
        posi[i] = "BangZhong";
    }
    for(int i = 3;i<n;++i){
        b[i].position = posi[i];
    }


    sort(b.begin(),b.end(),[&](auto A,auto B){
        if(level[A.position]!=level[B.position])return level[A.position]<level[B.position];
        if(A.rank != B.rank)return A.rank > B.rank;
        return A.dex < B.dex;
    });

    a = b;

    for(int i=0;i<3;++i){
        cout<<a[i].name<<" "<<a[i].position<<" "<<a[i].rank<<endl;
    }
    for(int i=3;i<n;++i){
        cout<<a[i].name<<" "<<a[i].position<<" "<<a[i].rank<<endl;
    }


    return 0;
}