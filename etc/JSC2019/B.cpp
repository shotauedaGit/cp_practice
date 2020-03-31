#include <bits/stdc++.h>

using namespace std;

#define INF 1001001001  //int32_t
#define MOD 1000000007
#define MOD2 998244353

#define all(a)  (a).begin(),(a).end()

#define mkp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int mmul(int p,int q,int m){
    ll lp=p,lq=q; return (int)(((lp%m)*(lq%m))%m);
}

int mpow(int x,int n,int m){
    ll res=x,ans=1;
    while(n!=0){
        if(n%2==0){ res = mmul(res,res,m);n>>=1;
        }else{      ans = mmul(ans,res,m);--n;}
    }
    return (int)ans;
}

int mdiv(int p,int q,int m){
    return mmul(p,mpow(q,m-2,m),m);
}

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    ll n,k;
    cin >>n>>k;
    ll in=0,tr=0;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >>a[i];
    }
    

    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if(a[j] < a[i])in++;
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(i == j)continue;

            if(a[j] < a[i])tr++;
        }
    }

    //cout <<endl<< in << " " << tr<<endl;

    ans += mmul(in,k,MOD);
    //cout << in << " x " << k<<endl;
    ans %= MOD;

    ll mul = k*(k-1)/2;
    mul %= MOD;

    ans += mmul(tr,mul,MOD);
    ans %= MOD;
    
    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}

