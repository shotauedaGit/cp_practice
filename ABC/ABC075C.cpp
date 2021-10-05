#include <bits/stdc++.h>
using namespace std;

#define INF 2147483647
#define LINF 9223372036854775807
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
typedef long double ld;

typedef pair<int,int> P;
typedef pair<int,P> iP;
typedef pair<P,P> PP;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int dx8[8] ={1,1,0,-1,-1,-1, 0, 1};
int dy8[8] ={0,1,1, 1, 0,-1,-1,-1};

chrono::system_clock::time_point  start;
void Timer_start(){start = std::chrono::system_clock::now();}
double Timer_end(){
    auto end = std::chrono::system_clock::now();
    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count(); //処理に要した時間をミリ秒に変換
    return elapsed;
}

class Unionfind{
    public:
    
    int n;vector<int> par;
    Unionfind(int _n){par.resize(_n);n=_n;init();}
    void init(){rep(i,n)par[i]=i;}

    int root(int x){// 0-idx
        if(x == par[x])return x;
        else return (par[x] = root(par[x]));
    }
    void unite(int x,int y){par[ root(x) ] = root(y);}
    bool same(int x,int y){return (root(x) == root(y));}
};

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int n,m;cin>>n>>m;
    vector<P> e(m);

    rep(i,m){
        int ai,bi;
        cin>>ai>>bi;
        --ai;--bi;

        e[i].fi = ai;
        e[i].se = bi;
    }


    Unionfind uf(n);
    rep(i,m){
        uf.init();
        rep(j,m){
            if(j!=i)uf.unite(e[j].fi,e[j].se);
        }
        
        bool quit = false;
        rep(j,n){
            rep1(k,j+1,n){
                if(uf.same(j,k) == false){
                    ++ans;
                    quit = true;
                    break;
                }
            }
            if(quit)break;
        }
    }
    cout<<ans<<endl;

    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    return 0;
}
