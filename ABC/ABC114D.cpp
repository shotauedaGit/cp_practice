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

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int n;
    cin>>n;

    vector<int> primelist;
    rep1(i,2,n+1){
        bool isprime = true;
        rep1(j,2,i-1){
            if(i%j == 0)isprime=false;
        }
        if(isprime)primelist.eb(i);
    }

    int nP = primelist.size();
    vector<int> exp;

    for(int p:primelist){
        int pf = p;
        int tmp=0;

        while(pf <= n){
            tmp += n/pf;
            pf *= p;
        }
        exp.eb(tmp);
    }


    rep(i,nP)if(exp[i] >= 74)++ans;

    int two=0,thr=0;
    rep(i,nP){
        rep1(j,i+1,nP){
            if(i == j)continue;
            int p = exp[i];
            int q = exp[j];

            if( (p >= 24&&q >= 2) )++two;
            if( (p >= 14&&q >= 4) )++two;
            if( (q >= 24&&p >= 2) )++two;
            if( (q >= 14&&p >= 4) )++two;
        }
    }

    rep(i,nP){
        rep1(j,i+1,nP){
            rep1(k,j+1,nP){
                int p = exp[i];
                int q = exp[j];
                int r = exp[k];

                if(p>=4&&q>=4&&r>=2)++thr;
                if(p>=4&&q>=2&&r>=4)++thr;
                if(p>=2&&q>=4&&r>=4)++thr;
            }
        }
    }
    ans += two + thr;
    cout<<ans<<endl;
    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
