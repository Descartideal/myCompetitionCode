#include <bits/stdc++.h>
using namespace std;


int main(){
    int cnt = 0;
    for(int a=0;a<3;++a){
        for(int b=0;b<3;++b){
            for(int c=0;c<3;++c){
                for(int d=0;d<3;++d){
                    if(((a*d%3)-(b*c%3)+3)%3==1){
                        cnt++;
                        cout<<a<<" "<<b<<endl;
                        cout<<c<<" "<<d<<endl;
                        cout<<endl;
                    }
                }
            }
        }
    }

    cout<<"cnt:"<<cnt<<endl;

    return 0;
}