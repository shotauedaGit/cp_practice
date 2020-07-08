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





int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int n,m,k;
    cin>>n>>m>>k;

    vector<ll> a(n),sa(n);
    vector<ll> b(m),sb(m);

    rep(i,n)cin>>a[i];
    rep(i,m)cin>>b[i];

    sa[0] = a[0];
    sb[0] = b[0];

    rep1(i,1,n){
        sa[i] = sa[i-1] + a[i];
    }
    rep1(i,1,m){
        sb[i] = sb[i-1] + b[i];
    }

    auto st = upper_bound(all(sa),k);
    if(st == sa.begin()){
    }else{

    --st;

    while(1){
        int nA = st - sa.begin() + 1;

        ll t = *st;

        auto st2 = upper_bound(all(sb),k-t);--st2;
        int nB = st2 - sb.begin() + 1;

        //db2(nA,t);
        //db2(nB,k-t);
        //ln;

        --st;
        chmax(ans,nA+nB);

        if(nA == 1)break;
    }

    }



    int allB = upper_bound(all(sb),k) - sb.begin();
    chmax(ans,allB);

    cout<<ans<<endl;

    //cout <<fixed<<setprecision(16)<< << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
