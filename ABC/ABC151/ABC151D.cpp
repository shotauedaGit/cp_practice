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
#define dig(n)  to_qring(n).length()

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define se second
#define fi first

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,pii> ppii;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}

int h,w;
int calc=0;


int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int bfs(vector<string>g,int st){
    int maxdist=0;
    vector<vector<bool>> vis(25,vector<bool>(25,false));
    queue<pii> q;

    q.push({st,0});
    vis[st/w][st%w]=true;

    while (!q.empty()){
        int cur=q.front().fi;
        int x=cur%w;
        int y=cur/w;
        int dist=q.front().se;
        chmax(maxdist,dist);
        q.pop();

        //db2(x,y);ln;
        //db3(y,x,dist);ln;
        rep(i,4){
            calc++;

            int nx=x+dx[i];
            int ny=y+dy[i];
            if((0<=nx&&nx<w)&&(0<=ny&&ny<h)){
                if(vis[ny][nx]==false && g[ny][nx]=='.'){
                    q.push({ny*w+nx,dist+1});
                    //chmax(maxdist,dist+1);
                    vis[ny][nx]=true;
                }
            }
        }
    }
    return maxdist;
}

int main(){
    bool flag=false;
    ll ans=0,sum=0;

    cin >>h>>w;
    vector<string> g(h);
    //vector<vector<int>> d(w*h,vector<int>(w*h,INF));
    rep(i,h)cin>>g[i];

    
    rep(i,h){
        rep(j,w){
            if(g[i][j]=='.')chmax(ans,bfs(g,i*w+j));
            //ln;db2(i,j);ln;
        }
    }
    //*/
    //cout <<fixed<<setprecision(16)<< << endl;
    cout<<ans<<endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
