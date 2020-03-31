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

    int n,k;
    cin >>n>>k;

    vector<int> res(n+1);
    res[0] = 1;

    for (int i = 1; i <= n; i++){
        res[i] = min(res[i-1]*2 , res[i-1]+k);
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << res[n] << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
