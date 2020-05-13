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

    int n,p;
    cin>>n>>p;

    ll dp[n][2]={};

    vector<int> a(n);
    int piv = (p+1)%2;

    rep(i,n)cin>>a[i];

    if(a[0]%2==0){
        if(p == 1){
            dp[0][1]=2;
        }else{
            dp[0][0]=2;
        }
    }else{
            dp[0][0]=1;
            dp[0][1]=1;
    }

    rep1(i,1,n){
        if(a[i]%2 == 0){
            dp[i][0] = dp[i-1][0]*2;
            dp[i][1] = dp[i-1][1]*2;
        }else{
            dp[i][0] = dp[i-1][1]+dp[i-1][0];
            dp[i][1] = dp[i-1][0]+dp[i-1][1];
        }
    }

    cout<<dp[n-1][0]<<endl;

    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    return 0;
}
