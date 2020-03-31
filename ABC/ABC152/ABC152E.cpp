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

ll mgcd(ll a,ll b){return b%MOD ? gcd(b%MOD , (a%MOD)%(b%MOD)) : a%MOD ;}
ll mlcm(ll a,ll b){return mdiv(((a%MOD)*(b%MOD)),mgcd(a,b),MOD);}


void mfac(int x,int *f,int m){//O(n)
    *f=1; for(int i=1;i<=x;++i)f[i]=mmul(f[i-1],i,m);}

void mfiv(int x,int *f,int fx,int m){//O(n)
    f[x] = mdiv(1,fx,m); 
    for(int i=x;i>0;--i)f[i-1]=mmul(f[i],i,m);}

int mncr(int n,int r,int m,int* fac,int* fiv){//O(1)
    return mmul(fac[n],mmul(fiv[r],fiv[n-r],m),m);}

int pr[1000000];
bool is_p[1001001];

int seive(int n){
    int p=0;
    fill(is_p,is_p+n,true);

    is_p[0]=is_p[1]=false;

    rep1(i,2,n+1){
        if(is_p[i]){
            pr[p++]=i;
            for(int j=2*i;j<=n;j+=i)is_p[j]=false;
        }
    }
    return p;
}

int main(){
    bool flag=false;
    ll ans=0,ml=1,alcm=1,agcd;
    int sum=0;

    int maxfc=0;
    int n,pn;
    cin >>n;

    pn=seive(1001000);
    vector<int> fct(pn,-1);

    vector<ll> a(n);
    map<int,int> app;
    map<int,int> fctm;

    rep(i,n){
        cin>>a[i];

        ml = mmul(ml,a[i],MOD);

        if(app[a[i]]==1)continue;
        int ai=a[i];
        for(int j=0; pr[j] <= sqrt(a[i])+1 ; ++j){
            int cnt=0;
            while (ai %pr[j]==0){
                cnt++;
                ai /= pr[j];
            }
            //if(cnt==0)continue;
            chmax(fctm[pr[j]],cnt);
            chmax(fct[j],cnt);
            chmax(maxfc,j+1);
            if(ai <= 1)break;
        }
        if(ai>1)chmax(fctm[ai],1);
        app[a[i]]=1;
    }

    //db2(maxfc,pn);
    ll tLCM=1;
    //rep(i,maxfc)tLCM =mmul(tLCM, mpow(pr[i],fct[i],MOD),MOD);

    for(auto p:fctm)tLCM =mmul(tLCM, mpow(p.fi,p.se,MOD),MOD);

    //for(auto p:fctm){db2(p.fi,p.se);ln;}

    //db2(ml,tLCM);ln;

    rep(i,n){
        ll add = mdiv(ml,a[i],MOD);
        //db2(a[i],add);ln;
        sum = (sum +add)%MOD;
    }

    sum = mmul(sum,tLCM,MOD);
    sum = mdiv(sum,ml,MOD);

    //cout <<fixed<<setprecision(16)<< << endl;
    cout<<sum<<endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
