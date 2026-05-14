//#include <bits/extc++.h>

//using namespace __gnu_pbds;
//using V = pair<int, int>;
/** 
int main(){
    tree<V, null_type, less<V>, rb_tree_tag, tree_order_statistics_node_update> ver;
    map<int, int> dic;

    int n,q; cin >> n >> q;
    for (int i = 1, op, x; i <= n; i++) {
        op = 1;
        cin>>x;

        if (op == 1) { // 插入一个元素x，允许重复
            ver.insert({x, ++dic[x]});
        } else if (op == 2) { // 删除元素x，若有重复，则任意删除一个
            ver.erase({x, dic[x]--});
        } else if (op == 3) { // 查询元素x的排名（排名定义为比当前数小的数的个数+1）
            cout << ver.order_of_key({x, 1}) + 1 << endl;
        } else if (op == 4) { // 查询排名为x的元素
            cout << ver.find_by_order(--x)->first << endl;
        } else if (op == 5) { // 查询元素x的前驱
            int idx = ver.order_of_key({x, 1}) - 1; // 无论x存不存在，idx都代表x的位置，需要-1
            cout << ver.find_by_order(idx)->first << endl;
        } else if (op == 6) { // 查询元素x的后继
            int idx = ver.order_of_key( {x, dic[x]}); // 如果x不存在，那么idx就是x的后继
            if (ver.find({x, 1}) != ver.end()) idx++; // 如果x存在，那么idx是x的位置，需要+1
            cout << ver.find_by_order(idx)->first << endl;
        }
    }

    for(int i=1;i<=q;++i){
        int k,x,op;cin>>k;
        if(k>0){
            op=1;x=k;
            ver.insert({x, ++dic[x]});
        }else{
            x = -k;
            k = ver.find_by_order(--x)->first
            ver.erase({k, dic[k]--});
        }
    }

    cout << ver.find_by_order(--1)->first << endl;
}
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v)os<<x<<" ";
    os<<"\n";
    return os;
}

#define d(x) cerr<<"#---"<<#x<<"=="<<x<<"\n";

inline int lowbit(int x){
    return x&-x;
}

struct BIT{
    int n;
    vector<int> a;

    BIT(int _n,const vector<int>& w){
        n=_n;
        a.resize(n+1,0);
        for(int i=1;i<=n;++i){
            add(i,w[i]);
        }
    }

    void add(int x,int v){
        for(;x<=n;x+=lowbit(x)){
            a[x]+=v;
        }
    }

    ll sum(int x){
        ll res = 0;
        for(;x;x-=lowbit(x)){
            res += a[x];
        }
        return res;
    }

    ll sum(int l,int r){
        return sum(r)-sum(l-1);
    }
};

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,q;cin>>n>>q;
    vector<int> ls(1);
    vector<int> a(n+1);
    for(int i=1;i<=n;++i){
        cin>>a[i];
        ls.push_back(a[i]);
    }
    vector<int> ex(q+1);
    for(int i=1;i<=q;++i){
        cin>>ex[i];
        if(ex[i]>=1)ls.push_back(ex[i]);
    }

    sort(ls.begin()+1,ls.end());
    ls.erase(unique(ls.begin()+1,ls.end()),ls.end());

    int m = ls.size()-1;

    //d(a)d(ex)d(ls)d(m)

    auto lsh = [&](int x){
        return lower_bound(ls.begin(),ls.end(),x)-ls.begin();
    };

    //cerr<<lsh(2)<<endl;

    vector<int> w(m+1,0);
    for(int i=1;i<=n;++i){
        int pos = lsh(a[i]);
        w[pos]++;
    }

    //d(w);

    BIT bit(m,w);

    auto qu = [&](int dex){
        int l=1,r=m,mid=(l+r)>>1;
        while(l<r){//cerr<<7;
            //d(mid);d( bit.sum(mid) );d(dex);
            if(bit.sum(mid)<dex){
                l = mid+1;
            }else{
                r = mid;
            }
            mid=(l+r)>>1;
        }
        return mid;
    };

    for(int i=1;i<=q;++i){
        int x = ex[i];
        if(x>=1){
            bit.add(lsh(x),1);
        }else{
            x = -x;
            bit.add(qu(x),-1);
        }
    }

    if(bit.sum(m)>0){
        cout<<ls[qu(1)]<<"\n";
    }else{
        cout<<0<<"\n";
    }

    return 0;
}