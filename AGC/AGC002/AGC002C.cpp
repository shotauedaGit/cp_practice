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

int main(){

    bool flag=true;
    ll ans=0,sum=0;

    int n,l;
    cin>>n>>l;
    vector<int> a(n);

    int mxl=0,lstn;
    cin>>a[0];
    rep(i,n-1){
        cin>>a[i+1];

        if( a[i+1]+a[i] > mxl){
            mxl = a[i+1]+a[i];
            lstn = i+1;
        }
    }

    if(mxl < l)flag=false;

    vector<int>ansarr;
    if(flag){
        rep(i,lstn)ansarr.eb(lstn-i);
        rep1(i,lstn+1,n)ansarr.eb(i);
        reverse(all(ansarr));
        
        cout<<"Possible"<<endl;
        for(int ai:ansarr)cout<<ai<<endl;
    
    }else{
        cout<<"Impossible"<<endl;
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    return 0;
}
