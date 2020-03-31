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

    bool flag=false;

    ll ans=1e13,sum=0;
    
    ll n;
    cin >>n;

    for (int i = 1; i <= (int)sqrt(n); i++){
        if(n%i == 0){
            ll p = i;
            ll q = n/i;
            ans = min(p+q-2,ans);
        }
    }
    
    ans = min(n-1,ans);

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
