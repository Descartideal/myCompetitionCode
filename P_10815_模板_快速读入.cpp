#ifdef __unix__
#define gc getchar_unlocked
#else
#define gc _getchar_nolock
#endif


#include <cstdio>
#include <cctype>
using namespace std;

int readint(){
    int k=0,f=1,c=gc();
    for(;!isdigit(c);c=gc()){
        if(c=='-')f=-1;
    }
    for(;isdigit(c);c=gc()){
        k = k*10+(c^48);
    }
    return k*f;
}

int main(){
    int n=readint();
    int sum = 0;
    for(int i=0;i<n;++i){
        sum+=readint();
    }
    printf("%d",sum);
    return 0;
}