#include <bits/stdc++.h>
using namespace std;

#define INF 1001001001
#define LINF 1001001001001001001

#define MOD 1000003
#define MOD2 998244353

#define all(a)  (a).begin(),(a).end()
#define dig(n)  to_string(n).length()
#define pb push_back
#define eb emplace_back
#define mkp make_pair
#define se second
#define fi first

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,pii> ppii;

#define mkf(n,mod)  static int fact[(n)+1]={}; mfac((n),fact,(mod)); //enables to let x!=fact[x]
#define mkfiv(n,mod)  static int finv[(n)+1]={}; mfiv((n),finv,fact[n],(mod)); // 1/x! = finv[x]

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
    //return mdiv(f[n],mmul(f[r],f[n-r],m),m);
    return mmul(fac[n],mmul(fiv[r],fiv[n-r],m),m);}

int fact[1<<20]={};
int main(){
    bool flag=false;
    ll ans=0,sum=0;

    //mkf(MOD+10,MOD);
    //mkfiv(MOD,MOD);

    mfac((1000010),fact,(MOD));

    int q;
    cin >>q;

    for (int i = 0; i<q; i++){
        int x,d,ni;
        cin >>x>>d>>ni;

        int st = mdiv(x,d,MOD);
        int ed = st+ni-1;

        //cout << st << "  " <<ed<<endl;
        if( st/MOD != ed/MOD ){
            cout << "0" <<endl;
            continue;
        }

        int stf=fact[st%MOD];
        //int edf=finv[( st+ni-1 )%MOD];
        int edf=fact[ed];
        //cout <<stf<<"  "<<edf<<endl;

        int p = mmul(mdiv(edf,stf,MOD),st,MOD);
        //cout << mmul( mmul(stf,edf,MOD) , mpow(d,ni,MOD) ,MOD) << endl;
        cout << mmul( p , mpow(d,ni,MOD) ,MOD) << endl;
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    return 0;
}
