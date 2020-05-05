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

void kousei(int st,int p,vector<P>& a){
        //cout<<"kousei ..."<<st<<" to "<<st+p<<endl;

        rep(i,p-1){
            a[st+i].fi = st+i+1;
            a[st+i+1].se = st+i+1;
        }
        a[st].se = st+p;
        a[st+p-1].fi = st+p;
}

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int n,m;
    cin>>n;

    int c = n,cnt=0;
    while(c%2==0){c/=2;++cnt;}

    if( c>1 ){
        vector<P> a(n,P(0,0));
        puts("Yes");
        cout<<n<<endl;

        rep(i,(1<<cnt)){
            kousei(i*c,c,a);
        }

        rep(i,n)cout<<2<<" "<<a[i].fi<<" "<<a[i].se<<endl;
    }else{
        puts("No");
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    return 0;
}
