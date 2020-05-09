#include <bits/stdc++.h>
using namespace std;

#define INF (1<<30)-1
#define LINF (1LL<<62)-1LL
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
    ll ans=INF,sum=0;

    int d,g;
    cin>>d>>g;
    vector<P> pr(d);

    rep(i,d){
        int pi,ci;
        cin>>pi>>ci;
        pr[i] = P(pi,ci);
    }



    rep(i , (1<<d)){
        vector<int> cb(d,0);
        int cur = i;
        
        int acCount = 0;
        int pointSum = 0;

        rep(j,d){
            cb[j] = cur%2;
            cur /= 2;
        }

        rep(j,d){
            //cout<<cb[j]<<",";

            if(cb[j]==1){
                acCount += pr[j].fi;
                pointSum += 100*(j+1)*pr[j].fi;
                pointSum += pr[j].se;
            }
        }

        rep(j,d){
            int p = d-1-j;
            if(pointSum >= g)break;
            if(cb[p]==0){
                int rem = g - pointSum;
                int task = (rem+(100*(p+1))-1)/(100*(p+1));

                int slv = min(pr[p].fi , task);

                acCount += slv;
                pointSum += (p+1)*100*slv;

            }
        }

        //db(acCount);ln;

        if(pointSum >= g){
            chmin(ans,acCount);
        }
    }



    cout<<ans<<endl;

    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    return 0;
}
