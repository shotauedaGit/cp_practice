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

int mmul(int p,int q,int m){ //O(1)?
    ll lp=p,lq=q; return ((lp%m)*(lq%m))%m;}

int mpow(int x,int n,int m){ //O(logN)
    ll res=x,ans=1;
    while(n!=0){
        if(n%2==0){ res = mmul(res,res,m);n>>=1;
        }else{      ans = mmul(ans,res,m);--n;}}return ans;}

int mdiv(int p,int q,int m){ //O(logMOD)
    return mmul(p,mpow(q,m-2,m),m);}

#define mkprm(n) int *prime=(int *)malloc((n+1)*sizeof(int)); bool *isp=(bool *)malloc((n+1)*sizeof(bool)); seive(n,isp,prime);

int seive(int n,bool *isp,int *prime){
    fill(isp,isp+n+1,true);int p=0;isp[0]=isp[1]=false;
    for(int i=2;i<=n;++i){if(isp[i]){prime[p++]=i;for(int j=2*i;j<=n;j+=i)isp[j]=false;}}
    prime[p]=-1;return p;
}

int main(){
    bool flag=false;
    ll ans=1,sum=0;

    int n;
    cin >>n;

    mkprm(n);
    for(int i=0;prime[i]!=-1;++i){
        int tmp=n;
        int fcts=0;

        while (tmp>1){
            fcts += tmp/prime[i];
            tmp/=prime[i];
        }
        //db2(prime[i],fcts);ln;
        ans = mmul(ans,fcts+1,MOD);
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout<<ans<<endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
