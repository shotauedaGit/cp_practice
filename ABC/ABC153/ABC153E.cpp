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

int dp[1010][20010]={};

int main(){
    bool flag=false;
    ll ans=INF,sum=0,mx=0;

    int h,n;
    cin >>h>>n;

    vector<int> a(n);
    vector<int> b(n);
    rep(i,n){
        cin>>a[i];
        cin>>b[i];
        chmax(mx,a[i]);
    }
    rep(i,n+1)rep(j,h+mx+1)dp[i][j]=INF;
    rep(i,n+1)dp[i][0]=0;

    rep(i,n){
        rep(j,h+mx+1){
            if(j-a[i] >= 0){
                dp[i+1][j] = min(dp[i][j], dp[i+1][j - a[i]] + b[i]);
            }else{
                dp[i+1][j] = dp[i][j];
            }
        }
    }

    /*
    rep(i,n+1){
        printf("%d th magic  ",i);
        rep(j,h+mx+1){
            if(dp[i][j]==INF)printf(" INF");
            else printf("%4d",dp[i][j]);
        }
        ln;
    }
    //*/

    rep1(i,h,h+mx)chmin(ans,dp[n][i]);

    //cout <<fixed<<setprecision(16)<< << endl;
    cout<< ans <<endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    return 0;
}
