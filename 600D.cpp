#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define int ld
#define sqrt sqrtl
#define abs fabsl

#define db(x) cerr<<"#---"<<#x<<"=="<<x<<endl;
#define cerr if(0)cerr

const ld Pi = 4.0*atanl(1);

struct Point{
    ld x,y;

    ld operator*(const Point& other)const{
        return x*other.x+y*other.y;
    }
};

ld dist(const Point& a,const Point& b){
    ld dx = a.x-b.x;
    ld dy = a.y-b.y;
    return sqrtl( dx*dx + dy*dy );
}

ld distLine(const Point& a,ld A,ld B,ld C){
    return fabsl(A*a.x+B*a.y+C)/sqrtl(A*A+B*B);
}

ld Heron(ld a,ld b,ld c){
    ld p = (a+b+c)/2;
    return sqrtl(p*(p-a)*(p-b)*(p-c));
}

ld sinesLaw(ld r,ld celta){
    return (r*r*sinl(celta))/2.0;
}

signed main(){
    //cerr<<Heron(3,4,5)<<endl;
    Point a,b;
    ld ar,br;
    cin>>a.x>>a.y>>ar;
    cin>>b.x>>b.y>>br;

    if(ar>br){
        swap(a,b);
        swap(ar,br);
    }

    cout<<fixed<<setprecision(20);
    ld d = dist(a,b);
    if(d>=ar+br){
        cout<<0.0L<<endl;
        return 0;
    }

    ld 
    A = 2.0*(b.x-a.x),
    B = 2.0*(b.y-a.y),
    C = a*a-b*b + br*br-ar*ar;

    ld ad = distLine(a,A,B,C), bd = distLine(b,A,B,C);

    db(ad);
    db(bd);

    ld al,bl,l;
    al = sqrtl(ar*ar-ad*ad);
    bl = sqrtl(br*br-bd*bd);
    l = (al+bl);

    db(l);

    ld aCelta = acosl(ad/ar);
    ld bCelta = acosl(bd/br);

    ld ans = 0;
    if(bd<=d){
        cerr<<"A---------\n";
        db(aCelta);
        db(bCelta);
        db(ar);
        db(br);
        db(aCelta*ar*ar-Heron(ar,ar,l));
        db(bCelta*br*br-Heron(br,br,l));

        ans = ( aCelta*ar*ar-sinesLaw(ar,2.0*aCelta) )  +  ( bCelta*br*br-sinesLaw(br,2.0*bCelta) );
    }else if(br<d+ar){
        cerr<<"B---------\n";
        ans = (Pi*ar*ar - aCelta*ar*ar + sinesLaw(ar,2.0*aCelta)) + (bCelta*br*br-sinesLaw(br,2.0*bCelta));
    }else{
        cerr<<"C---------\n";
        ans = Pi*ar*ar;
    }
    cout<<ans<<endl;

    return 0;
}