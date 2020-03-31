#include <bits/stdc++.h>

using namespace std;

#define INF 1001001001
#define LINF 1001001001001001001
#define MOD 1000000007
#define MOD2 998244353

#define all(a)  (a).begin(),(a).end()

#define pb push_back
#define eb emplace_back
#define mkp make_pair

#define se second
#define fi first

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,pii> ppii;




struct cedge{
    int to;
    int cost;
    cedge (int t ,int c) : to(t) , cost(c) {}
};

struct graph{ // if not any edge costs 1 , do cost().  Construter : numOfVs , isDirected , has minuscost (3 overloads)

    bool directed=false;
    bool cost=false;
    bool minuscost=false;
    
    bool ZeroIndexed=false;

    bool isdistcalced = false;
    
    int nv;

    //priority_queue< cedge,vector<cedge>,greater<cedge> > edges;
    vector< vector<cedge> > g;

    vector<int> dist;
    vector<int> prev;
    vector<bool> visited;

    vector<int> edgeCol;


    void setv(int n){
        dist.resize(n);
        visited.resize(n);
        prev.resize(n);
        edgeCol.resize(n-1);

        fill(all(dist),INF);
        fill(all(visited),false);
        fill(all(prev),-1);
    }

    void reset(){
        fill(all(dist),INF);
        fill(all(visited),false);
        fill(all(prev),-1);

        isdistcalced = false;
    }

    void setcosttrue(){
        cost=true;
    }

    void set0indexed(){
        ZeroIndexed = true;
    }

    graph(int n) : nv(n),g(n){setv(n);}
    graph(int n,bool direct): nv(n),g(n) , directed(direct) {setv(n);}
    graph(int n,bool direct,bool cost) : nv(n),g(n) , directed(direct) , cost(cost) {setv(n);}

    void init(int m){
        for (int i = 0; i < m; i++){
            int a,b,c;

            if(cost)cin>>a>>b>>c;
            else {
                cin>>a>>b;
                c=i+1;
            }

            if(!ZeroIndexed){--a;--b;}

            cedge e(b,c);
            cedge re(a,c);

            g[a].push_back(e);
            if(!directed)g[b].push_back(re);
        }
    }

    void initmat(){
        int f;
        for (int i = 0; i < nv; i++)
        {
            for (int j = 0; j < nv; j++)
            {
                int f;
                cin >>f;

                if(f > 0){
                    cedge e(0,0),re(0,0);

                    if(cost){
                            e=cedge(i,f);
                            re=cedge(j,f);
                    }else{
                            e = cedge(i,1);
                            re = cedge(j,1);
                    }

                    g[j].push_back(e);
                    if(!directed)g[i].push_back(re);
                }
            }
        }
    }

    void bfs(){
        queue<int> que;
        que.push(1);

        while(que.size()){
            int cur=que.front();
            visited[cur]=true;
            que.pop();

            for (int j = 0; j < g[cur].size(); j++){

                cedge e=g[cur][j];
                int nex = e.to;

                if(visited[nex]==true)continue;
                que.push(nex);

            }
        }
    }

    vector<int> getpath(int t){  // returns vector-type shortest path to t(1-indexed).
        if(!ZeroIndexed)--t;

        vector<int> path;
        
        for(; t!=-1;t = prev[t])path.push_back(t+1);
        reverse(all(path));

        return path;
    }


    
    void showpath(int t){
        vector<int> path = getpath(t);

        for(int i = 0;i < path.size();++i){
            cout <<"-"<< path[i] <<" - ";
        }
        cout << endl;
    }
    


    void showdist(){
        int s;
        int maxdist=0;
        for (int i = 0; i < dist.size(); i++)
        {

            if(dist[i] == INF)cout << "dist to "<<i+1<< "is TBD"<<endl;
            else {
                cout << "dist to "<<i+1<< "=" <<dist[i]<<endl;
                maxdist = max(maxdist,dist[i]);
            }

            if(dist[i] == 0){
                cout << "#this is s" <<endl;
                s = i+1;
            }
        }

        cout << "s was" << s <<endl << "maxdist is" <<maxdist<<endl;; 
    }

    int bfs0();
    void bfsCol(int c);

};


    int graph::bfs0(){
        vector<bool> vis(nv,false);
        int maxdim = 0;
        queue<int> que;
        que.push(1);

        while(que.size()){
            int cur=que.front();
            vis[cur]=true;
            que.pop();

            for (int j = 0; j < g[cur].size(); j++){
                maxdim = max(maxdim,(int)g[cur].size());

                cedge e=g[cur][j];
                int nex = e.to;

                if(vis[nex]==true)continue;
                que.push(nex);

            }
        }
        return maxdim;
    }

    void graph::bfsCol(int c){
        vector<int> pro(nv,-1);
        vector<bool> vis(nv,false);

        int curC;
        queue<int> que;
        que.push(1);

        while(que.size()){
            int cur=que.front();

            //cout << cur+1 << " visted"<<endl;
            vis[cur]=true;
            que.pop();

            curC=1;
            for (int j = 0; j < g[cur].size(); j++){
                //puts("0");
                //if(curC > c)puts("bug in Col\n");
                cedge e=g[cur][j];
                int curN = e.cost;
                int nex = e.to;
                //cout <<curN<<" th e is "<<cur+1<<" to "<<nex+1<<endl;
                //puts("1");
                
                if(vis[nex]==true){
                    continue;
                }

                if(cur!=1){
                    if(pro[cur] == curC)++curC;
                }

                edgeCol[curN-1]=curC;
                //puts("3");

                //cout << "edge:"<<curN <<"s col ="<<curC<<endl;

                que.push(nex);
                pro[nex]=curC;
                //puts("4");

                curC++;
            }
        }
    }

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int n;
    cin >>n;

    graph g(n,false,false);
    g.ZeroIndexed=false;
    g.init(n-1);

    int col = g.bfs0();

    g.bfsCol(col);


    //cout <<fixed<<setprecision(16)<< << endl;
    cout << col << endl;
    for (int i = 0; i < n-1; i++){
        cout << g.edgeCol[i] << endl;}
    

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
