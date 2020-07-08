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


struct corn{
    ll x=0,r=0,h=0;
    corn(){}
    corn(ll xi,ll ri,ll hi):x(xi),r(ri),h(hi){}
};


int main(){

    bool flag=false;
    ll ans=0;

    int n,q;
    cin>>n>>q;


    const ld PI = acosl(-1.0);
    vector<ld> sum(20010,0);
    vector<corn> cornArr(n);

    rep(i,n){
        ll xi,ri,hi;
        cin>>xi>>ri>>hi;
        cornArr[i] = corn(xi,ri,hi);
    }

    rep(i,n){
        ll xi,ri,hi;
        xi = cornArr[i].x;
        ri = cornArr[i].r;
        hi = cornArr[i].h;

        rep1(j,1,hi+1){
            ld p = j*j*j*ri*ri*PI;
            ld q = hi*hi*3;

            sum[xi+(hi-j)] = p/q;
        }
    }

    rep1(i,1,20010){
        sum[i] += sum[i-1];
    }


    rep(i,q){
        int a,b;
        cin>>a>>b;

        if(a == b)cout<<"0.000000"<<endl;
        else if(a == 0){
            cout<<fixed<<setprecision(16)<< sum[b-1]<<endl;
        }else{
            cout<<fixed<<setprecision(16)<< sum[b-1] - sum[a-1]<<endl;
        }
    }


    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    return 0;
}
