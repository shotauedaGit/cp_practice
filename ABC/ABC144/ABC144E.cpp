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

bool ok(vector<ll> f,vector<ll> a,ll k,ll x){
    ll sum=0;

    for (int i = 0; i < a.size(); i++){
        sum += max(0LL,a[i]-(x/f[i]));
    }

    return k >= sum;
}

int main(){

    bool flag=false;

    ll ans=0,sum=0;
    
    ll n,k;
    cin >>n>>k;
    vector<ll> a(n),f(n);

    for (int i = 0; i < n; i++){
        cin >>a[i];
    }

    for (int i = 0; i < n; i++){
        cin >>f[i];
    }

    sort(all(a));
    sort(all(f),greater<ll>());
    ll l = -1,r = 1e13;

    while(l+1 < r){
        ll c = (l+r)/2;

        if(ok(f,a,k,c)){
            r = c;
        }else{
            l = c;
        }
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << r << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
