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

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int a,b;
    cin >>a>>b;

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << max(max(a+b,a-b),a*b) << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
