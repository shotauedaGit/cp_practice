#include <bits/stdc++.h>

using namespace std;

#define INF 1001001001
#define LINF 1001001001001001001
#define MOD 1000000007
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

int mmul(ll p,ll q,int m){ //O(1)?
    ll lp=p,lq=q; return ((lp%m)*(lq%m))%m;
}

int mpow(ll x,ll n,int m){ //O(logN)
    ll res=x,ans=1;
    while(n!=0){
        if(n%2==0){ res = mmul(res,res,m);n>>=1;
        }else{      ans = mmul(ans,res,m);--n;}}return ans;}


int mdiv(ll p,ll q,int m){ //O(logMOD)
    return mmul(p,mpow(q,m-2,m),m);
}

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int n,mxbit=0;
    cin >>n;
    vector<ll> a(n);
    vector<int> bc(64,0);
    map<ll,int>app;

    for (int i = 0; i < n; i++){
        cin >>a[i];

        //app[a[i]]++;

        int p=0;
        ll tmp=a[i];

        while (tmp>0){
            if(tmp%2==1){
                bc[p]++;

                mxbit=max(mxbit,p);
            }

            tmp/=2;
            ++p;
        }
    }

    /*
    for (int i = 0; i <= mxbit; i++)
    {
        cout << bc[i]<<" ";
    }
    puts("\n");
    */


    for (int i = 0; i < n; i++){
        ll tmp=a[i];
        int p=0;

        bool f=false;
        for(int p=0;p <= mxbit;++p){
            
            if(tmp%2==0 || f){
                ans =(ans + mmul(bc[p], mpow(2,p,MOD) ,MOD) %MOD);
            }else{
                ans =(ans + mmul(n-bc[p], mpow(2,p,MOD),MOD) %MOD);
            }
            if(tmp<=0)f=true;
            else tmp/=2;
        }
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << mdiv(ans,2,MOD) << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
