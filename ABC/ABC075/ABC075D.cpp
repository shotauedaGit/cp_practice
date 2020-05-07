#include <bits/stdc++.h>
using namespace std;

#define INF (1<<31)-1
#define LINF (1LL<<63)-1LL

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

int main(){

    bool flag=false;
    ll ans=LINF,sum=0;

    int n,k;
    cin>>n>>k;
    vector<P> po(n);

    vector<int> xl(n);
    vector<int> yl(n);

    rep(i,n){
        int x,y;
        cin>>x>>y;
        po[i] = P(x,y);
        xl[i]  =x;
        yl[i]  =y;
    }

    sort(all(xl));sort(all(yl));

    rep(a,n)rep1(b,a,n)rep(c,n)rep1(d,c,n){
        
        ll x2 = xl[b];
        ll x1 = xl[a];
        ll y2 = yl[d];
        ll y1 = yl[c];

        int cnt=0;
        rep(i,n){
            int x = po[i].fi;
            int y = po[i].se;
            
            if( x1<=x&&x<=x2 && y1<=y&&y<=y2 ){
                ++cnt;
            }
        }

        if(cnt >= k){
            chmin(ans,(x2-x1)*(y2-y1));
        }
    }

    cout<<ans<<endl;

    //cout <<fixed<<setprecision(16)<< << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
