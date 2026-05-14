#include <bits/stdc++.h>
using namespace std;

#define d(x) cerr<<"#---"<<#x<<"=="<<x<<endl;

signed main(){
    int n;cin>>n;
    int m;

    auto query = [&](int l,int r)
    {
        if(l>r)
            swap(l, r);
        cout<<"? "<<l<<" "<<r<<endl;
        int re;cin >> re;
        return re;
    };

    m = query(1,n);

    int l = 1, r = n, mid = (l + r) >> 1;
    while(l<r){
        d(l);d(r);
        int re;
        if(m<l){
            re = query(m, mid);
            if(re==m){
                r = mid;
            }else{
                l = mid + 1;
            }

        }else if(l<=m && m<=mid){
            if(r-l==1){
                break;
            }
            re = query(l, mid);
            if(re==m){
                r = mid;
            }else{
                l = mid + 1;
            }
        }else if(mid<=m && m<=r){
            if(r-l<=1){
                break;
            }
            re = query(mid, r);
            if(re==m){
                l = mid;
            }else{
                r = mid-1;
            }
        }else{
            re = query(mid + 1, m);
            if(re==m){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        mid = (l + r) >> 1;
    }
    if(l==m){
        mid = r;
    }
    if(r==m){
        mid = l;
    }

    cout << "! " << mid << endl;
    return 0;
}