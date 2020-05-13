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

typedef pair<int,int> P;
typedef pair<int,P> iP;
typedef pair<P,P> PP;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int n;
    cin>>n;
    vector<int> a(n),b(n),c(n);

    rep(i,n)cin>>a[i];
    rep(i,n)cin>>b[i];
    rep(i,n)cin>>c[i];

    sort(all(a));sort(all(b));sort(all(c));
    vector<ll> pat(n+1,0),conb(n,0),cona(n,0);

    int bp=n-1,cp=n-1;
    while(bp >= 0){
        while(c[cp] > b[bp] && cp>=0 ){
            --cp;
        }
        conb[bp] = n-1 - cp;
        --bp;
    }

    bp=n-1;
    int ap=n-1;
    while(ap >= 0){
        while(b[bp] > a[ap] && bp>=0 ){
            --bp;
        }
        cona[ap] = n-1 - bp;
        --ap;
    }

    rep1(i,1,n+1){
        pat[i] = pat[i-1] + conb[n-i];
        //db2(i,pat[i]);ln;
    }

    rep(i,n){
        ans += pat[ cona[i] ];
    }

    /*
    ln;
    rep(i,n)cout<<cona[i]<<" ";
    ln;
    rep(i,n)cout<<conb[i]<<" ";
    ln;
    */

    cout<<ans<<endl;
    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
