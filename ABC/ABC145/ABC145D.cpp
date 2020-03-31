#include <bits/stdc++.h>

using namespace std;

#define INF 1001001001  //int32_t
#define MOD 1000000007
#define MOD2 

#define all(a)  (a).begin(),(a).end()

#define mkp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define mkf(n,MOD)  int fact[(n)+1]={}; mfac((n),fact,(MOD)) //enables to let x!=fact[x]



int mmul(int p,int q,int m){ //O(1)?
    ll lp=p,lq=q; return ((lp%m)*(lq%m))%m;
}

int mpow(int x,int n,int m){ //O(logN)
    ll res=x,ans=1;
    while(n!=0){
        if(n%2==0){ res = mmul(res,res,m);n>>=1;
        }else{      ans = mmul(ans,res,m);--n;}
    }
    return ans;
}

int mdiv(int p,int q,int m){ //O(logMOD)
    return mmul(p,mpow(q,m-2,m),m);
}

void mfac(int x,int *f,int m){//O(n)
    *f=1; for(int i=1;i<=x;++i)f[i]=mmul(f[i-1],i,m);
}

int mncr(int n,int r,int m,int* f){//O(logMOD)
    return mdiv(f[n],mmul(f[r],f[n-r],m),m);
}


int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int x,y;
    cin >>x>>y;

    mkf(1001001,MOD);

    if((x+y)% 3 != 0){
        puts("0");
        return 0;
    
    }else{
        if(y > 2*x){
            puts("0");
            return 0;
        }else if(y > 2*x){
            puts("0");
            return 0;
        }

        int n = (x+y)/3;

        //vector<int> fact = modfact(n,MOD);
        int r = 2*n - x;

        /*
        int nf=modfacts(n);
        int rf=modfacts(r);
        int nrf=modfacts(n-r);

        ans = moddiv(nf,modmul(rf,nrf,MOD),MOD);
        */

        ans = mncr(n,r,MOD,fact);

    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
