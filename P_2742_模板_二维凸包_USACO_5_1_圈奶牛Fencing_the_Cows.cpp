#include <bits/stdc++.h>
using namespace std;
using d = double;

#define db(x) cerr<<"#---"<<#x<<"=="<<x<<endl;

struct Point{
    d x,y;
    bool operator<(const Point& other)const{
        if(x!=other.x)return x<other.x;
        return y<other.y;
    }

    bool operator==(const Point& other)const{
        return (x==other.x)&&(y==other.y);
    }

    Point operator-(const Point& other)const{
        return Point{x-other.x,y-other.y};
    }
};

d cross(const Point& a,const Point& b){
    return a.x*b.y-a.y*b.x;
}

d cross(const Point& a,const Point& b,const Point& c){
    return cross((b-a),(c-a));
}

d dist(const Point& a,const Point& b){
    d dx = a.x-b.x;
    d dy = a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}

signed main(){
    int n;cin>>n;
    vector<Point> p(n+1);for(int i=1;i<=n;++i)cin>>p[i].x>>p[i].y;

    sort(p.begin()+1,p.end());
    p.erase(unique(p.begin()+1,p.end()),p.end());

    int m = (int)p.size()-1;

    if(m==1){
        cout<<0.00<<endl;
        return 0;
    }

    if(m==2){
        cout<<fixed<<setprecision(2)<<2.0*dist(p[1],p[2])<<endl;
        return 0;
    }


    int top=0;
    vector<Point> stk(2*m+5);
    for(int i=1;i<=m;++i){
        while(top>=2 && cross(stk[top-2],stk[top-1],p[i])<=0)top--;
        stk[top++] = p[i];
    }

    int lowerSize = top;
    for(int i=m-1;i>=1;--i){
        while(top>lowerSize && cross(stk[top-2],stk[top-1],p[i])<=0)top--;
        stk[top++] = p[i];
    }

    top--;

    //db(top);


    d ans = 0;
    for(int i=0;i<top;++i){
        //db(stk[i].x);
        //db(stk[i].y);
        ans += dist(stk[i],stk[(i+1)%top]);
    }
    cout<<fixed<<setprecision(2)<<ans<<endl;

    return 0;
}