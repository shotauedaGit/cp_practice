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

ll f(ll x){
    ll sh=(1<<0),ret=0;

    while(sh <= x){

        ll bitnum = ((x+1)/(2*sh))*sh + max(((x+1)%(2*sh))-sh , 0LL);

        if(bitnum%2 == 1){
            ret += sh;
        }

        sh <<= 1;
    }

    return ret;
}

int main(){

    bool flag=true;

    ll ans=0,sum=0;
    
    ll a,b;
    cin >>a>>b;

    ans = f(max(a-1,0LL)) ^ f(b);
    cout << ans <<endl;

    /*for (ll i = a; i < b+1; i++)
    {
        cout << i << " -> "<<f(i)<<endl;
    }*/
    

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
