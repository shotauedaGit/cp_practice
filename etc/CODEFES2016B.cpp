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

int main(){
    ll ans=0,sum=0;
    ll n;
    cin >>n;
    
    ll k,skip;
    k = ceil((sqrt(8*n+1)-1)/2);

    skip = k*(k+1)/2 - n;

    for (int i = 1; i <= k; ++i){
        if(i == skip)continue;
        cout << i << endl;
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
