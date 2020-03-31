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

    ll ans=0,sum=0;
    
    int a,b;
    cin >>a>>b;
    

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    if(a < 10 && b < 10)cout << a*b <<endl;
    else cout << -1 <<endl;
    
    return 0;
}
