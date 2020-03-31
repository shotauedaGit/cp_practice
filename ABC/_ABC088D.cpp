#include <bits/stdc++.h>
using namespace std;

#define INF 1001001001
#define LINF 1001001001001001001
#define MOD 1000000007
#define MOD2 998244353

#define all(a)  (a).begin(),(a).end()
#define dig(n)  to_string(n).length()

#define pb push_back
#define eb emplace_back
#define mkp make_pair

#define se second
#define fi first

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,pii> ppii;

struct p{
    int x,y;
    p(int a,int b){
        x = a;
        y = b;
    }
};

vector<pii> dirc = {{1,0},{0,-1},{-1,0},{0,1}};

typedef pair<int,p> pip;

int main(){
    bool flag=false;
    ll ans=0,bl=0;

    int h,w;
    cin >>h>>w;
    vector<string> g(h);
    vector<vector<bool>> vis(h,vector<bool>(w,false));
    vector<vector<int>> dist(h,vector<int>(w,INF));

    for (int i=0; i<h; i++){
        cin>>g[i];
        for(int j = 0; j < w;j++){
            if(g[i][j]=='#')bl++;
        }
    }

    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({0,0});
    dist[0][0]=0;
    
    while (!q.empty()){
        pii cur = q.top();
        q.pop();

        int x = (cur.se)%w;
        int y = (cur.se)/w;

        if(dist[y][x] < cur.fi)continue;

        for (pii d:dirc){
            int nx = x + d.fi;
            int ny = y + d.se;

            if(w > nx && nx >= 0 && h > ny && ny >= 0 && g[ny][nx]=='.'){
                if(dist[ny][nx] > dist[y][x]+1){
                    dist[ny][nx] = dist[y][x]+1;
                    q.push({dist[ny][nx], ny*w + nx });
                }
            }
        }
    }
    ans = (w*h)- dist[h-1][w-1] -bl-1;

    /*
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            if(dist[i][j]==INF)cout<<" INF";
            else printf("%4d",dist[i][j]);
        }
        puts("");
    }
    */
    

    //cout <<fixed<<setprecision(16)<< << endl;
    if(dist[h-1][w-1] == INF)cout << -1 << endl;
    else cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
