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
    ll ans=0,sum=0;

    int a,b,q;
    cin>>a>>b>>q;

    vector<ll> s(a+1);
    vector<ll> t(b+1);

    s[0] = (1LL<<62);t[0] = (1LL<<62);

    rep(i,a)cin>>s[i+1];
    rep(i,b)cin>>t[i+1];

    s.eb(-(1LL<<62));t.eb(-(1LL<<62));

    rep(i,q){
        ll x;
        cin>>x;

        int p = lower_bound(all(s),x)-s.begin();
        int q = lower_bound(all(t),x)-t.begin();


        ll tmp = LINF;

        rep1(i , max(0,p-3) , min(p+3,a+1)){
            rep1(j, max(0,q-3) , min(q+3,b+1)){
                ll si = s[i];
                ll ti = t[j];

                if(((si==x) || (ti==x))){

                    chmin( tmp , abs(si-x)+abs(ti-x) );

                }else if( (si<x)!=(ti<x) ){

                    chmin( tmp , abs(si-x)+abs(ti-x) + min(abs(si-x),abs(ti-x)) );

                }else{
                    
                    chmin( tmp , max(abs(si-x),abs(ti-x)) );
                }
            }
        }

        cout << tmp << endl;
    }

    //cout <<fixed<<setprecision(16)<< << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
