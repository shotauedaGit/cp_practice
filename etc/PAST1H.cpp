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

/* to do
    単品売りはすべて通す。
    
    奇数番目、全体の現在の最小値を保持しておいて、最小値で足りないクエリが来たらスルー。
    足りるなら、まとめ売りで何枚を累計売ったか記憶しておく(odd,al)
*/

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int n,q;
    cin>>n;
    vector<ll> c(n);
    
    ll mnOd=LINF,mn=LINF;
    rep(i,n){
        cin>>c[i];
        if(i%2==0)chmin(mnOd,c[i]);
        chmin(mn,c[i]);
    }

    ll odd=0,al=0;

    cin>>q;
    rep(i,q){
        int op;cin>>op;

        if(op==1){

            int x,a;
            cin>>x>>a;--x;

            if(c[x] < a)continue;
            c[x] = c[x]-a;ans+=a;

            if(x%2==0)chmin(mnOd,c[i]);
            chmin(mn,c[i]);

        }else if(op==2){
            int a;cin>>a;

            if(mnOd < a)continue;
            odd += a;
            mnOd -= a;

        }else{
            int a;cin>>a;

            if(mn < a)continue;
            al += a;
            mn -=a;
        }
    }

    ans += odd*n/2;
    if(n%2==1)ans+=odd;

    ans += al*n;
    cout<<ans<<endl;
    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    return 0;
}
