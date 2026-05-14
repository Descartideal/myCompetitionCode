#include <bits/stdc++.h>
#define cerr if(0)cerr

using namespace std;

using pii = pair<int,int>;

using i64 = long long;
using ll = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

using b32 = bitset<32>;
using b64 = bitset<64>;

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v)os<<x<<" ";
    return os;
}

template<class T>
istream& operator>>(istream& is, vector<T>& v){
    for(auto& x:v)is>>x;
    return is;
}

struct plar{
    int N=-1,S=-1,E=-1,W=-1;
};

inline void solve(){
    int k;cin>>k;
    int pointSum;
    int pointMax=0;
    vector<vector<int>> g(2*k+1);
    vector<int> deg(2*k+1,0);
    for(int i=1;i<=k;++i){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
        pointMax = max({pointMax,u,v});
    }
    pointSum = pointMax;
    vector<int>factor;
    for(int i=1;i<=pointMax;++i){
        if(pointMax%i==0){
            factor.push_back(i);
        }
    }
    
    if(k==0){
        cout<<2<<"\n";
        return;
    }


    if(pointMax==4){
        cout<<-1<<endl;
        return;
    }

    if(factor.size()==2){
        cout<<1+pointMax<<endl;
        return;
    }

    
    if(deg[1]==1){
        if(pointMax==k+1){
            cout<<1+pointMax<<endl;
        }else{
            cout<<-1<<endl;
        }
        return;
    }

    if(deg[1]==2){
        if(pointMax==k){
            cout<<1+pointMax<<endl;
        }else{
            cout<<-1<<endl;
        }
        return;
    }

    if(deg[1]==3){
        cout<<2+(pointMax/2)<<'\n';
        return;
    }

    for(int i=1;i<=pointMax-1;++i){
        if(deg[i]!=deg[i+1]){
            cout<<-1<<'\n';
            return;
        }
    }

    if(k!=2*pointMax){
        cout<<-1<<endl;
        return;
    }

    vector<plar> point(pointMax+1);
    

    auto isBorder = [&](int x,int y,int center){
        cerr<<"isBorder:"<<center<<" "<<x<<" "<<y<<endl;
        vector<int> gather;
        for(int A:g[x]){
            if(A!=y && A!=center){cerr<<A<<" ";
                gather.push_back(A);
            }
        }cerr<<endl;

        cerr<<"isBorder--B"<<endl;

        for(int B:g[y]){
            if(B!=x && B!=center){
                auto it = find(gather.begin(),gather.end(),B);
                if(it==gather.end()){
                    gather.push_back(B);
                }else{
                    cerr<<"isBorder--OK"<<endl;
                    return B;
                }
            }
        }

        cerr<<"isBorder--000"<<endl;

        return 0;
    };

    auto relative = [&](int edge,int center){
        cerr<<"relative:"<<edge<<" "<<center<<endl;
        for(int y:g[center]){cerr<<"find(relative): "<<y<<endl;
            if(y==edge)continue;
            if(!isBorder(edge,y,center)){
                return y;
            }
        }
        return 0;
    };

    auto addEdge = [&](int x,int y,int direction){
        if(direction==0){
            point[x].N = y;
            point[y].S = x;
        }else if(direction==1){
            point[x].E = y;
            point[y].W = x;
        }else if(direction==2){
            point[x].S = y;
            point[y].N = x;
        }else{
            point[x].W = y;
            point[y].E = x;
        }
    };

    auto fixRelative = [&](int x){cerr<<"fixRelative"<<endl;
        plar& A = point[x];
        int y;
        if(A.N!=-1){
            y = relative(A.N,x);
            A.S = y;
            point[y].N = x;
        }
        if(A.E!=-1){
            y = relative(A.E,x);
            A.W = y;
            point[y].E = x;
        }
        if(A.S!=-1){
            y = relative(A.S,x);
            A.N = y;
            point[y].S = x;
        }
        if(A.W!=-1){
            y = relative(A.W,x);
            A.E = y;
            point[y].W = x;
        }
    };

    auto fixBorder = [&](int x){cerr<<"fixBorder"<<endl;
        int border;
        
        border = isBorder(point[x].N,point[x].E,x);
        addEdge(point[x].N,border,1);
        addEdge(point[x].E,border,0);
   
        cerr<<"fixBorder--1st"<<endl;

        border = isBorder(point[x].S,point[x].E,x);
        addEdge(point[x].S,border,1);
        addEdge(point[x].E,border,2);

        border = isBorder(point[x].N,point[x].W,x);
        addEdge(point[x].N,border,3);
        addEdge(point[x].W,border,0);

        border = isBorder(point[x].W,point[x].S,x);
        addEdge(point[x].W,border,2);
        addEdge(point[x].S,border,3);
    };

    //start
    point[1].N = g[1][0];
    if(isBorder(g[1][0],g[1][1],1)){
        point[1].E = g[1][1];
    }else if(isBorder(g[1][0],g[1][2],1)){
        point[1].E = g[1][2];
    }
    
    vector<int> w(pointMax+1,0),vis(pointMax+1,0);
    queue<int> q;q.push(1);
    vis[1] = 1;
    //--------------

    
    while(!q.empty()){
        int x = q.front();q.pop();cerr<<endl<<"BFS:"<<x<<endl;

        {
            plar a = point[x];
            int cnt = 0;
            if(a.E>0){
                cnt++;
            }
            if(a.N>0){
                cnt++;
            }
            if(a.S>0){
                cnt++;
            }
            if(a.W>0){
                cnt++;
            }
            cerr<<x<<"--reload_deg = "<<cnt<<endl;
        }

        fixRelative(x);
        fixBorder(x);

        {
            cerr<<x<<"--N:"<<point[x].N<<endl;
            cerr<<x<<"--E:"<<point[x].E<<endl;
            cerr<<x<<"--S:"<<point[x].S<<endl;
            cerr<<x<<"--W:"<<point[x].W<<endl;
        }
        
        for(int y:g[x]){
            if(vis[y])continue;
            vis[y] = 1;
            q.push(y);
        }
    }

    int n=0,m=0;
    int s;
    
    s = 1;
    while(1){
        n++;
        s = point[s].N;
        if(s==1){
            break;
        }
    }
    
    s=1;
    while(1){
        m++;
        s = point[s].E;
        if(s==1){
            break;
        }
    }

    cout<<n+m<<endl;
	return;
}


signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}


















/*
***** Orz  Kiropo *******
*　　┏┓　　　┏┓+ +
*　┏┛┻━━━┛┻┓ + +
*　┃　　　　　　　┃
*　┃　　　━　　　┃ ++ + + +
*  ████━████+
*  ◥██◤　◥██◤ +
*　┃　　　┻　　　┃
*　┃　　　　　　　┃ + +
*　┗━┓　　　┏━┛
*　　　┃　　　┃ + + + +Code is far away from 　
*　　　┃　　　┃ + bug with the animal protecting
*　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
*　　　┃ 　　　　　　 ┣┓
*　　  ┃ 　　　　　 　┏┛
*　    ┗┓┓┏━┳┓┏┛ + + + +
*　　　　┃┫┫　┃┫┫
*　　　　┗┻┛　┗┻┛+ + + +
*/

//————自由是遗忘的左伴随


/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣤⡀⣀⣠⣤⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⡀⢀⣴⣾⣷⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣷⣾⣿⣷⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⠿⠛⠛⠉⠉⠉⠉⠉⠉⠛⠻⠿⣿⣿⣿⣿⣿⣶⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⡿⠿⠛⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠿⣿⣿⣿⣷⣄⡀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣀⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⣰⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠿⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣠⣾⣿⣿⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣶⣄⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣻⣿⣿⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢹⣿⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⠁⠈⢢⡀⠀⠀⠀⢸⡇⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⡟⠒⢦⡀⠀⠀⠀
⠀⠀⣠⣤⣤⣼⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⡇⠀⠀⠀⠉⢢⣄⠀⠀⢿⠊⠳⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣷⡄⠀⢷⠀⠀⠀
⠀⢰⠇⠀⣰⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⡌⣹⠗⠦⣬⣇⠀⠉⢢⡀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⡀⢸⡄⠀⠀
⠀⡟⠀⣼⣯⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣆⢹⡀⠀⠀⠀⠉⠁⠀⠀⢀⣀⡁⠀⠀⠉⠳⢴⡆⠀⠀⠀⠀⠀⠀⢹⣧⠈⡇⠀⠀
⠀⡇⠀⠀⢻⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣾⠻⠉⠛⠂⠀⠀⠀⠀⠀⠀⠻⠿⣿⣿⣿⣶⣦⡀⠛⣇⠀⠀⠀⠀⠀⣈⣿⠀⡇⠀⠀
⢸⡇⠀⠀⢠⣿⣷⣦⣀⡸⣷⣦⣶⡂⠉⠉⠉⢁⣤⣶⡶⠀⠀⠀⣀⣀⡴⠀⠀⠀⠀⠀⠀⠈⠉⠉⠁⠀⡟⢀⣴⣟⣰⣾⣿⣏⣠⠇⠀⠀
⠈⡇⠀⠀⢸⣿⠁⠉⣿⠛⠛⠃⡇⠀⠀⢠⣶⣿⡿⠛⠁⠀⠀⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠼⢿⠟⠿⢿⡏⠀⠘⣿⡀⠀⠀⠀
⠀⢷⣀⣀⣿⠇⠀⠀⢿⡇⠀⢀⢱⡀⠀⠛⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠀⠀⢸⠇⠀⠀⢹⣿⣄⠀⠀
⠀⠀⣉⣿⡏⠀⠀⠀⠀⠀⠀⢸⣇⣳⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡰⣿⠃⠀⠀⠀⠀⠀⠀⣿⠈⢧⠀
⠀⠘⣿⣿⠁⠀⠀⠀⠀⠀⠀⠘⣿⡛⣶⠀⠀⣠⠔⠒⠛⠒⠦⡀⠀⠀⠀⠀⣠⡤⠶⠤⢤⣀⠀⠀⠀⢀⣏⡄⠀⠀⠀⠀⠀⡀⣿⡆⠈⣧
⣠⡾⠛⣿⣿⣧⠀⠀⠀⠀⢸⣿⠾⢿⡿⠀⣰⠃⠀⠀⠀⠀⠀⢹⡄⠀⠀⡼⠁⠀⠀⠀⠀⠈⠙⣦⠀⢸⣿⡇⣾⣣⡀⠀⢰⣿⣿⣿⣤⠾
⡟⠀⠀⠻⣿⡟⢷⡄⣤⡀⠈⣿⡀⣸⠇⠀⠏⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⡇⢀⡀⠀⠀⠀⠀⢀⡟⠀⠀⠋⣿⣿⣿⡇⣠⣿⠿⠛⢷⡀⠀
⠀⠀⠀⠀⣿⣇⣨⣿⣿⣿⣦⣽⣷⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠃⠀⠙⠢⠤⠤⠴⢾⠀⠀⠀⠀⢸⣷⣿⣿⠟⠁⠀⠀⠈⣧⠀
⠀⠀⠀⠀⠈⠉⠉⠁⠈⠉⠈⢉⣿⡁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⣿⠀
*/