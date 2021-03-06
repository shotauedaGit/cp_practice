#include <bits/stdc++.h>
using namespace std;

#define INF 1001001001
#define LINF 1001001001001001001
#define MOD 1000000007
#define MOD2 998244353

template<class T,class U>bool chmax(T &a, const U &b){if(a<b){a=b;return 1;}return 0;}
template<class T,class U>bool chmin(T &a, const U &b){if(b<a){a=b;return 1;}return 0;}

#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)
#define rep1(i,a,b) for(int a_=(a),b_=(b),i=a_;i<b_;++i)
#define repr(i,n) for(int _i=(n),i=_i;i>0;--i)

#define db(x) cerr<<#x<<" = "<<x<<" ";
#define db2(x,y) cerr<<"("<<#x<<", "<<#y<<") = ("<<x<<", "<<y<<") ";
#define db3(x,y,z) cerr<<"("<<#x<<", "<<#y<<", "<<#z<<") = ("<<x<<", "<<y<<", "<<z<<") ";
#define ln cout<<endl;

#define all(a)  (a).begin(),(a).end()
#define dig(n)  to_string(n).length()

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define se second
#define fi first

typedef long long ll;

typedef pair<int,int> P;
typedef pair<int,P> iP;
typedef pair<P,P> PP;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


struct iv{
    
};

struct ie{
    ie():isUsed(0){}
    int aaa;
    int isUsed;
};


class edge{
    public:

    int frm;
    int to;
    int cost;

    edge(int f,int t):frm(f),to(t){};
    edge(int f,int t,int c):frm(f),to(t),cost(c){};
};



class Graph{
    public:

    int nV;
    int nE;

    vector<iv> vinfo;

    vector<vector<ie> > einfo;
    vector<P> elist;

    vector< vector< edge > > g;
    Graph(int _nV,int _nE):nV(_nV),nE(_nE){

        g.resize(nV);
        vinfo.resize(nV);

        einfo.resize(nV);
        rep(i,nV)einfo[i].resize(nV);

    }

    void addE(int u,int v){//無効グラフの時は逆方向もちゃんと張ろう
        edge e(u,v,1);
        g[u].eb(e);
    }

    void addE(int u,int v,int cost){ //無効グラフの時は逆方向もちゃんと張ろう
        edge e(u,v,cost);
        g[u].eb(e);
    }

    vector<int> dijkstra(int s){ //0idx_
        vector<int> dist(nV,INF);
        vector<int> par(nV,-1);


        dist[s] = 0;

        vector<bool> vis(nV,false);
        priority_queue< P, vector<P> , greater<P> > que;
        que.push(P(0,s));

        while(!que.empty()){
            P vd = que.top(); que.pop();

            int cur = vd.se;
            int cdist = vd.fi;
            vis[cur] = true;

            if(par[cur] != -1){
                einfo[cur][par[cur]].isUsed = 1;
                einfo[par[cur]][cur].isUsed = 1;
            } 

            // cout<<"visit : "<<cur<<endl;

            rep(i , g[cur].size()){
                edge e = g[cur][i];
                int nex = e.to;
                int cost = e.cost;

                if(vis[nex])continue;//ここで親じゃない頂点引いたら閉路あり？

                if(chmin( dist[nex] , cdist+cost )){
                    //cout<<s<<" -- "<<nex<<" => "<<dist[nex]<<endl;
                    par[nex] = cur;
                    que.push(P(dist[nex],nex));
                }else{
                }
            }
        }

        return dist;
    }

    vector<int> bellman_ford(int s){//NEGCYCLE => (returns EMPTY vector)
        vector<int> dist(nV,INF);
        dist[s] = 0;

        int roopcnt = 0;
        while(1){
            bool update = false;
            rep(i,nV)rep(j,g[i].size()){

                edge e = g[i][j];
                int from = e.frm;
                int nex = e.to;
                int cost = e.cost;

                if(dist[from]!=INF)if(chmin(dist[nex],dist[from]+cost))update=true;
            }

            if(update){
                ++roopcnt;
                if(roopcnt > nV-1){vector<int> negcy;return negcy;}
            }else break;

        }
        return dist;
    }

    vector< vector<ll> > warshall_floyid(){//NEGCYCLE => (returns EMPTY vector)
        vector< vector<ll> > dist(nV,vector<ll>(nV,LINF));

        rep(i,nV)dist[i][i] = 0;

        rep(i,nV)rep(j,g[i].size()){
            edge e = g[i][j];
            dist[e.frm][e.to] = e.cost;
        }

        rep(k,nV)rep(i,nV)rep(j,nV){
            if(!(dist[i][k]==LINF || dist[k][j]==LINF))chmin(dist[i][j],dist[i][k] + dist[k][j]);
        }

        rep(i,nV)if(dist[i][i]<0){vector<vector<ll> > negcy;return negcy;}
        return dist;
    }

};

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int n,m;
    cin>>n>>m;

    Graph g(n,m);

    rep(i,m){
        int a,b,c;
        cin >>a>>b>>c;
        --a;--b;
        g.elist.eb( P(a,b) );

        g.addE(a,b,c);
        g.addE(b,a,c);
    }

    rep(i,n){
        g.dijkstra(i);
    }

    rep(i,m){
        int u = g.elist[i].fi;
        int v = g.elist[i].se;
        if( g.einfo[u][v].isUsed == 0)++ans;
        else{
            //db2(u,v);cout<<" isUsed"<<endl;
        }

    }

    cout<<ans<<endl;

    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    return 0;
}
