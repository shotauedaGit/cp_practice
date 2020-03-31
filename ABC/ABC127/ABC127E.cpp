#include <bits/stdc++.h>

using namespace std;

#define INF ((1<<30)-1)  //int32_t
#define MOD 1000000007
#define MOD2 

#define all(a)  (a).begin(),(a).end()

#define mkp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


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

int mncr(int n,int r,int m ,int* fac,int* fiv){//O(1)
    return mmul(fac[n],mmul(fiv[r],fiv[n-r],m),m);}


int main(){

    ll ans=0;
    ll n,m,k;
    cin >>n>>m>>k;

    mkf(n*m,MOD);
    mkfiv(n*m,MOD);


    for(int i=1;i<=n;i++){
        int mul= mmul(mmul((n-i),(m*m)%MOD,MOD),mncr(n*m-2,k-2,MOD,fact,finv),MOD);
        int x = mmul(i,mul,MOD);
        ans = (ans + x)%MOD;
    }

    for(int i=1;i<=m;i++){
        int mul= mmul(mmul((m-i),(n*n)%MOD,MOD),mncr((n*m)-2,k-2,MOD,fact,finv),MOD);
        int y = mmul(i,mul,MOD);
        ans = (ans + y)%MOD;
    }

    cout << ans <<endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
