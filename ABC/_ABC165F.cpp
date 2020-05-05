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


struct tree{

    int nV;

    vector<vector<int>> g;
    vector<int> a;

    vector<int> ans;
    
    tree(int n){
        nV = n;

        g.resize(n);
        a.resize(n);

        ans.resize(n);
        fill(all(ans),0);

        rep(i,n)cin>>a[i];

        rep(i,n-1){
            int v,u;
            cin>>u>>v;
            --u;--v;

            g[u].eb(v);
            g[v].eb(u);
        }
    }

    void solve(){
        bfs(-1,0,1);
        rep(i, nV )cout<<ans[i]<<endl;
    }

    void bfs(int prev,int now,int curstreak){

        cout<<"visit : "<<now<<endl;
        
        if(prev != -1 && a[prev] < a[now]){
        
            curstreak++;
            chmax(ans[now] , max(ans[prev],curstreak));
        
        }else if(prev!=-1){
        
            curstreak=1;
            chmax(ans[now] , max(ans[prev],curstreak));
        
        }else{
            ans[now] = curstreak;
        }

        rep(i , g[now].size()){
            int nex = g[now][i];
            if(nex == prev)continue;

            bfs(now,nex,curstreak);
        }
    }

};

int main(){

    int n,m;
    cin>>n;
    tree tr(n);
    tr.solve();

    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    return 0;
}
