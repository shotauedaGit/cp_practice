#include <bits/stdc++.h>

using namespace std;

#define INF ((1<<30)-1)  //int32_t
#define MOD 1000000007
#define MOD2 

#define all(a)  (a).begin(),(a).end()

#define mkp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


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


    void setv(int n){
        dist.resize(n);
        visited.resize(n);
        prev.resize(n);

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
        for (int i = 0; i < m; i++)
        {
            int a,b,c;

            if(cost)cin>>a>>b>>c;
            else {
                cin>>a>>b;
                c=1;
            }

            if(!ZeroIndexed){--a;--b;}

            cedge e(b,c);
            cedge re(a,c);

            g[a].push_back(e);
            if(!directed)g[b].push_back(re);
        }
    }

    void initmat(){
        for (int i = 0; i < nv; i++)
        {
            for (int j = 0; j < nv; j++)
            {
                char f;
                cin >>f;

                //cout << f << " ";

                if(f != '0'){
                    int cost = (f-'0');

                    cedge e(0,0),re(0,0);

                    if(cost){
                            e=cedge(i,cost);
                            re=cedge(j,cost);
                    }else{
                            e = cedge(i,1);
                            re = cedge(j,1);
                    }

                    g[j].push_back(e);
                    if(!directed)g[i].push_back(re);
                }
            }
            
            //puts("\n");
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

    void dfs(){
        stack<int> st;
        st.push(1);

        while(st.size()){
            int cur=st.top();
            visited[cur]=true;
            st.pop();

            for (int j = 0; j < g[cur].size(); j++){

                cedge e=g[cur][j];
                int nex = e.to;

                if(visited[nex]==true)continue;
                st.push(nex);

            }
        }
    }



    void dijkstra(int s){
        int maxdist=0;

        if(!ZeroIndexed)--s;
        dist[s]=0;

        priority_queue < pii,vector<pii>,greater<pii> > que;
        que.push(pii(0,s));

        while(!que.empty()){
            pii p = que.top();
            int v = p.second;
            que.pop();

            if(dist[v] < p.first)continue;

            for (int i = 0; i < g[v].size(); i++){
                cedge e = g[v][i];

                //cout << dist[e.to]<<endl;
                if(dist[e.to] > dist[v] + e.cost){

                    //cout <<"distance to "<<e.to+1<< " = "<<dist[e.to]<< " > " <<dist[v] + e.cost<< '\n';

                    dist[e.to] = dist[v] + e.cost;  //cout << "cost update!" << endl;
                    maxdist = max(maxdist,dist[e.to]);

                    prev[e.to] = v;
                    que.push(pii((dist[e.to]),(e.to)));  //cout << "pushed!" << endl;
                }
            }
        }

        //return maxdist;
    }

    void bellmanford(int s){
        --s;
        dist[s]=0;

        bool update = true;

        while(update){
            update=false;

            for (int i = 0; i < nv; i++){
                for (int j = 0; j < g[i].size(); j++){
                    cedge e = g[i][j];
                    int v = e.to;
                    
                    //cout <<i+1<<" -> "<<v+1<<" costs "<<e.cost<< endl; 
                    //cout << "v=" << v+1 << endl; 

                    if((dist[i] != INF) && (dist[v] > dist[i] + e.cost)){

                        //cout <<"distance to "<<v+1<< " = "<<dist[v]<< " > " <<dist[i] + e.cost<< '\n';

                        dist[v] = dist[i] + e.cost; cout << "cost update!" << endl;
                        prev[v] = i;
                        update = true;
                    }
                }
            }
        }
    }

    void ecmp(){
        
    }

    void prim(){

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

    bool isbipart();

};


bool graph::isbipart(){
        bool f=true;

        stack<int> st;
        vector<int> color(nv,-1);
        st.push(1);
        color[0]=1;

        while(st.size()){
            int cur=st.top();
            visited[cur]=true;
            st.pop();

            for (int j = 0; j < g[cur].size(); j++){

                cedge e=g[cur][j];
                int nex = e.to;

                if(color[nex] == -1){
                    
                    color[nex] = (color[cur]+1)%2;

                    cout <<nex+1<<" is "<<color[nex]<<endl;

                }else if(color[nex] == color[cur]){
                    cout <<nex+1<<" = "<<cur+1<<endl;
                    return false;
                }

                if(visited[nex]==true)continue;

                st.push(nex);
            }
        }

        return f;
}



int main(){

    bool flag=true;
    int ans=0,sum=0;
    
    int n;
    string s;
    cin >>n;

    graph g(n,false,false);
    g.initmat();

    for (int i = 1; i <= n; i++){
        g.dijkstra(i);
        //g.showdist();
        //puts("\n");

        int maxd=0;
        for(int di : g.dist){
            if(di != INF)maxd = max(maxd,di);
        }

        ans = max(ans,maxd);

        g.reset();
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    if(g.isbipart())cout << ans+1 << endl;
    else cout << -1 <<endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
