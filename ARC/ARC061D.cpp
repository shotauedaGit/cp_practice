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

int dx8[8]={1,1,0,-1,-1,-1,0,1};
int dy8[8]={0,1,1,1,0,-1,-1,-1};


int main(){

    bool flag=false;
    ll sum=0;

    int h,w,n;
    cin>>h>>w>>n;

    map<P,int> cnt;

    rep(i,n){
        int x,y;
        cin>>y>>x;

        //db2(x,y);ln;
        
        if(! (x==1||x==w||y==1||y==h ))cnt[ P(x,y) ]++;

        rep(j,8){
            int nx = x+dx8[j];
            int ny = y+dy8[j];
            
            if(!(0<nx&&nx<=w&&0<ny&&ny<=h))continue;
            if(nx==1||nx==w||ny==1||ny==h)continue;
            
            cnt[ P(nx,ny) ]++;
            //db2(nx,ny);ln;

        }
    }



    vector<ll> ans(10,0);
    for(auto p:cnt){
        ans[ p.second ]++;

        //db3( p.first.first, p.first.second , p.second  );ln;

        sum++;
    }
    ans[0] = (ll)(h-2)*(w-2)-sum;
    
    rep(i,10)cout<<ans[i]<<endl;

    //cout <<fixed<<setprecision(16)<< << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
