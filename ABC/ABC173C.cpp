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

    int h,w,k;
    cin>>h>>w>>k;

    int d[6][6] = {};

    rep(i,h)rep(j,w){
        char c;cin>>c;
        if(c == '#')d[i][j]=1;
        else d[i][j]=0;
    }

    bool si[6];
    bool sj[6];

    rep(i , (1<<h)){
        int tmp = i;
        rep(p,h){
            if(tmp%2 == 1)si[p]=true;
            else si[p]=false;
            tmp/=2;
        }

        rep(j , (1<<w)){
            tmp = j;
            int bl = 0;

            rep(q,w){
                if(tmp%2 == 1)sj[q]=true;
                else sj[q]=false;
                tmp/=2;
            }

            rep(p,h)rep(q,w){
                if(si[p] || sj[q])continue;
                if(d[p][q] == 1)bl++;
            }

            if(bl==k)ans++;
        }
    }
    cout<<ans<<endl;

    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
