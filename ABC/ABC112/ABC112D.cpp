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

    bool flag=true;

    ll ans=0,sum=0;
    
    int n,m;
    cin >>n>>m;

    for (int i = 1; i*i <= m; i++){
        if(m % i ==0){
            if(m / i >= n)ans = max(ans,(ll)i);
            if( m/(m/i) >= n)ans = max(ans,(ll)(m/i));
        }
    }
    
    

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
