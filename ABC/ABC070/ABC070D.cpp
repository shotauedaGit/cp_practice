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
typedef pair<int,int> pii;
typedef pair<pii,pii> ppii;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

struct e{
    int to;
    int cost;
};

int n,q,k;
vector<vector<e>> g(101010);
vector<int> par(101010,-1);
vector<bool> vis(101010,false);
vector<ll> dist(101010,LINF);

void dijkstra(int s){
    priority_queue<pair<ll,int>,vector<pair<ll,int>>> q;
    q.push({0,s});
    
    vis[s]=true;
    dist[s]=0;
    par[s]=-1;

    while (!q.empty()){
        int cur=q.top().se;
        ll d=q.top().fi;
        q.pop();

        rep(i,g[cur].size()){
            int nex = g[cur][i].to;
            ll c = g[cur][i].cost;
            if(vis[nex]==true)continue;

            chmin(dist[nex],d+c);
            q.push({dist[nex],nex});
            vis[nex]=true;
            par[nex]=cur;
        }
    }
}

vector<int> getpath(int v){
    vector<int>path;
    for(int i=v;i!=-1;i=par[i]){
        //db(i);cout<<"-";
        path.emplace_back(i);
    }
    //path.emplace_back(s);
    reverse(all(path));
    return path;
}


int lca(int a,int b){
    vector<int> ap=getpath(a);
    vector<int> bp=getpath(b);

    int left=0,right=min(ap.size(),bp.size())-1;

    while(right - left > 1){
        int mid=(right+left)/2;
        if(bp[mid] == ap[mid])left=mid;
        else right = mid;
    }
    int lcav=ap[left];
    int dlca = dist[lcav];

    return dlca;
}



int main(){
    cin >>n;

    rep(i,n-1){
        int a,b,c;
        cin>>a>>b>>c;
        --a;--b;
        e ei={b,c};
        e rei={a,c};
        g[a].emplace_back(ei);
        g[b].emplace_back(rei);
    }

    cin>>q>>k;--k;
    vector<pii>que(q);
    
    dijkstra(k);
    
    /*
    rep(i,n){
        db(par[i]);ln;
    }
    int in;
    do{
        cin>>in;--in;
        db(dist[in]);cout<<"::";
        for(int vi:getpath(in))cout<<vi+1<<"-";

    }while(in!=-1);
    //*/
    rep(i,q){
        cin>>que[i].fi>>que[i].se;
        que[i].fi--;
        que[i].se--;

    }

    rep(i,q){
        int a,b;
        a=que[i].fi;
        b=que[i].se;
        
        cout << dist[a]+dist[b] << endl;
        //db3(dist[a],dist[b],lca(a,b));
    }



    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
