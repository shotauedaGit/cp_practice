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


#define mkf(n,mod)  int *fact=(int *)malloc((n+1)*sizeof(int)); mfac((n),fact,(mod)) //enables to let x!=fact[x]
#define mkfiv(n,mod)  int *finv=(int *)malloc((n+1)*sizeof(int)); mfiv((n),finv,fact[n],(mod)) // 1/x! = finv[x]

int mmul(int p,int q,int m){ //O(1)?
    ll lp=p,lq=q; return ((lp%m)*(lq%m))%m;}

int mpow(int x,int n,int m){ //O(logN)
    ll res=x,ans=1;
    while(n!=0){
        if(n%2==0){ res = mmul(res,res,m);n>>=1;
        }else{      ans = mmul(ans,res,m);--n;}}return ans;}

int mdiv(int p,int q,int m){ //O(logMOD)
    return mmul(p,mpow(q,m-2,m),m);}

void mfac(int x,int *f,int m){//O(n)
    *f=1; for(int i=1;i<=x;++i)f[i]=mmul(f[i-1],i,m);}

void mfiv(int x,int *f,int fx,int m){//O(n)
    f[x] = mdiv(1,fx,m); 
    for(int i=x;i>0;--i)f[i-1]=mmul(f[i],i,m);}

int mncr(int n,int r,int m,int* fac,int* fiv){//O(1)
    return mmul(fac[n],mmul(fiv[r],fiv[n-r],m),m);}



int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    bool flag=false;
    ll ans=0,sum=0;

    mkf(200010,MOD);
    mkfiv(200010,MOD);

    int n,a,b;
    cin >>n>>a>>b;

    ans = mpow(2,n,MOD);

    ans--;
    if(ans < 0)ans += MOD;

    int nCa=1,nCb=1;

    rep1(i,1,a+1){
        nCa = mmul(nCa,n-i+1,MOD);
        nCa = mdiv(nCa,i,MOD);
    }

    rep1(i,1,b+1){
        nCb = mmul(nCb,n-i+1,MOD);
        nCb = mdiv(nCb,i,MOD);
    }

    //db3(ans,nCa,nCb);ln;

    ans -= nCa;
    if(ans < 0)ans += MOD;

    ans -= nCb;
    if(ans < 0)ans += MOD;



    //cout <<fixed<<setprecision(16)<< << endl;
    cout<<ans<<endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
