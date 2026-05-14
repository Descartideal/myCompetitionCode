#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define db(x) cerr<<"#---"<<#x<<"=="<<x<<endl;
#define cerr if(0)cerr


template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto x:v)os<<x<<" ";
    return os;
}


struct Point{
    ll x,y;
    bool operator<(const Point& other)const{
        if(x!=other.x)return x<other.x;
        return y<other.y;
    }
    bool operator==(const Point& other)const{
        return x==other.x && y==other.y;
    }
    Point operator-(const Point& other)const{
        return Point{x-other.x,y-other.y};
    }
};

ostream& operator<<(ostream& os,const Point& a){
    os<<a.x<<","<<a.y<<" ";
    return os;
}


ll cross(const Point& a,const Point& b){
    return a.x*b.y-a.y*b.x;
}

ll cross(const Point& a,const Point& b,const Point& c){
    return cross(b-a,c-a);
}

ll dist2(const Point& a,const Point& b){
    ll dx = a.x-b.x;
    ll dy = a.y-b.y;
    return dx*dx+dy*dy;
}

vector<Point> convexHull(vector<Point>& p){
    sort(p.begin(),p.end());
    p.erase(unique(p.begin(),p.end()),p.end());

    int n = (int)p.size();
    if(n<=1){
        return p;
    }

    int top = 0;
    vector<Point> stk(2*n+5);

    for(int i=0;i<n;++i){
        while(top>=2 && cross(stk[top-2],stk[top-1],p[i])<=0)top--;
        stk[top++] = p[i];
    }
    int lowerSize = top;
    for(int i=n-2;i>=0;--i){
        while(top>lowerSize && cross(stk[top-2],stk[top-1],p[i])<=0)top--;
        stk[top++] = p[i];
    }
    if(n>1)top--;

    stk.resize(top);db(stk);
    return stk;
}

ll rotatingCalipers(const vector<Point>& p){
    int m = (int)p.size();
    if(m==1){
        return 0;
    }
    if(m==2){
        return dist2(p[0],p[1]);
    }

    int j=1;
    ll ans = 0;
    for(int i=0;i<m;++i){
        int ni = (i+1)%m;
        while( abs(cross(p[j],p[i],p[ni])) < abs(cross(p[(j+1)%m],p[i],p[ni])) ){
            j = (j+1)%m;
        }
        ans = max(ans,dist2(p[i],p[j]));
        ans = max(ans,dist2(p[ni],p[j]));
    }

    return ans;
}


signed main(){
    int n;cin>>n;
    vector<Point> p(n);for(int i=0;i<n;++i)cin>>p[i].x>>p[i].y;
    vector<Point> Hull = convexHull(p);
    cout<<rotatingCalipers(Hull)<<"\n";
    return 0;
}