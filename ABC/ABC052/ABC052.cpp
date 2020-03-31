#include <bits/stdc++.h>
using namespace std;

#define all(a)  (a).begin(),(a).end()

#define mkp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


int main(){
    bool flag=true;
    ll ans=0,sum=0;
    
    ll n,a,b;
    cin >>n>>a>>b;
    ll x[n];

    cin >>x[0];
    for (int i = 1; i < n; i++){
        cin >>x[i];

        if((x[i]-x[i-1])*a > b ){
            ans += b;
        }else{
            ans += (x[i]-x[i-1])*a;
        }
    }
    



    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
