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

ll a,b,c,d;



ll rec(ll n,ll cnt){

    cout<<n<<"   "<<cnt<<endl;

    if(n==1) return cnt+d;
    ll r2=LINF,r3=LINF,r5=LINF,r_1=LINF;
    if(n%2==0){r2=rec(n/2,cnt+a);}
    if(n%3==0){r3=rec(n/3,cnt+b);}
    if(n%5==0){r5=rec(n/5,cnt+c);}

    bool dok = true;

    if( n%2!=0 && n%3!=0 && n%5!=0 ){r_1=rec(n-1,cnt+d);}

    return min(min(r2,r_1),min(r5,r3));
}



int main(){

    bool flag=false;
    ll ans=0,sum=0;


    int t;cin>>t;

    rep(i,t){
        ll n;
        cin>>n>>a>>b>>c>>d;

        cout<<rec(n,0LL)<<endl;
    }


    //cout <<fixed<<setprecision(16)<< << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
