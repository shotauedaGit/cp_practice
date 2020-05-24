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

int n;
//
//vector<vector<int>> data(3, vector<int>(4));
//int od[n][n]={};

int main(){

    bool flag=false;
    ll ans=0,sum=0;


    cin>>n;
    ll nn = n*n;

    vector<vector<int>> od(n, vector<int>(n));
    //int od[n][n]={};

    rep(i,nn){
        int pi;
        cin>>pi;
        --pi;

        int ii = pi/n;
        int jj = pi%n;

        od[ii][jj] = i+1;
    }

    
    rep(i,n){
        rep(j,n){
            cout<<od[i][j]<<" ";
        }
        ln;
    }
    

    rep(i,n){rep(j,n){
        int l = j;
        int r = n-1-j;
        int u = i;
        int d = n-1-i;

        int cl=0,cr=0,cu=0,cd=0;

        rep(k,l){if(od[i][j-k-1] > od[i][j])++cl;}
        rep(k,r){if(od[i][j+k+1] > od[i][j])++cr;}
        rep(k,u){if(od[i-k-1][j] > od[i][j])++cu;}
        rep(k,d){if(od[i+k+1][j] > od[i][j])++cd;}

        int add = min(min(cu,cd),min(cl,cr));
        
        
        db2(od[i][j],add);cout<<"  ";
        db2(cu,cd);
        db2(cr,cl);ln;
        

        ans += add;
        }
    }

    cout<<ans<<endl;
    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
