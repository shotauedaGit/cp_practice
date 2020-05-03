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

typedef pair<int,int> P;
typedef pair<int,P> iP;
typedef pair<P,P> PP;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int n,m,q;
int mxp = 0;

int rec(int i,int *a,vector<vector<int>> rq){
    int point = 0;

    if(i == n-1){

        
        //rep(i,n)cout<<a[i]<<"  ";
        //*/

        rep(i,q){

            int ai = rq[i][0];
            int bi = rq[i][1];
            int ci = rq[i][2];
            int di = rq[i][3];

            //db2(ai,bi)
            //db2(ci,di)
            //ln;

            if(   a[bi]-a[ai]==ci  )point+=di;

        }
        //chmax(mxp,point);
        //db(point);ln;
        return point;

    }else{
        //vector<int> tp = a;
        rep1(j,a[i],m+1){
            a[i+1] = j;
            chmax(point ,rec(i+1,a,rq));
            //tp.pop_back();
        }

        return point;
    }
}

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    cin>>n>>m>>q;
    vector<vector<int>> rq(q,vector<int>(4));

    rep(i,q){
        rep(j,4){
            cin>>rq[i][j];
            if(j == 0 || j==1)--rq[i][j];
        }
    }


    rep1(i,1,m+1){
        //vector<int> a(n,0);
        
        int a[n] = {};
        a[0] = i;
        chmax(ans,rec(0,a,rq));
    }

    cout<<ans<<endl;

    //cout <<fixed<<setprecision(16)<< << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
