#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    string s;
    cin>>s;
    int n = s.length();
    int cntl = 0 , cntr = 0 , h = 0 , hmax = 0 , hmin = 1e6;
    for(int i = 0 ; i < n ; i ++){
        if (s[i] == 'p'){
            h ++ , hmax = max(h , hmax);
        }
        else if (s[i] == 'c'){
            h -- , hmin = min(h , hmin);
        }
        else if(s[i] == 'l'){
            cntl ++;
        }
        else{
            cntr ++;
            
        }
    }
    if(hmin == 1e6){
        hmin = 0;
    }
    if(h != 0){
        cout<<"No"<<endl;
        return ;
    }

    
    int finh = hmax - hmin + 1 , start = - hmin;
    vector<int>num(finh,0);
    
    for(int i = 0 , curh = start ; i < n ; i ++){
        if (s[i] == 'p'){
            curh ++;
        }
        else if (s[i] == 'c'){
            curh --;
        }
        else if(s[i] == 'l'){
            if(curh == start){
                if(num[curh] == 0){
                    num[curh] = -1;
                }
                else if (num[curh] == 1){
                    num[curh] = 10;
                }            
            }
            else if (curh == hmax){
                if(num[curh] == 0){
                    num[curh] = -1;
                }
                else if (num[curh] == 1){
                    num[curh] = 10;
                }            
            }
        }
        else if(s[i] == 'r'){
            if(curh == start){
                if(num[curh] == 0){
                    num[curh] = 1;
                }
                else if (num[curh] == -1){
                    num[curh] = 10;
                }            
            }
            else if (curh == hmax){
                if(num[curh] == 0){
                    num[curh] = 1;
                }
                else if (num[curh] == -1){
                    num[curh] = 10;
                }            
            }
        }
    }    
    
    cerr<<hmin<<" "<<hmax<<endl;

    if(num[hmax + start] != 0 && num[hmax + start] != 10){
        cout<<"No"<<endl;
        return ;            
    }
        
    cout<<"Yes"<<endl;
    return ;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    //t = 1;
    while(t --){
        solve();
    }
    
    return 0;
}