#include <bits/stdc++.h>

using namespace std;

#define INF 1001001001  //int32_t
#define LINF 1001001001001001001
#define MOD 1000000007
#define MOD2 998244353

#define all(a)  (a).begin(),(a).end()

#define pb push_back
#define eb emplace_back
#define mkp make_pair

#define se second
#define fi first

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int n;
    cin >>n;
    vector<ll> a(n),rsum(n);

    for (int i = 0; i < n; i++){
        cin >>a[i];
        sum += a[i];
    }

    rsum[0] = a[0];
    for (int i = 1; i < n; i++){
        rsum[i] = rsum[i-1] + a[i];
    }

    ll diff=LINF;
    for (int i = 0; i < n; i++){
        diff = min(diff,abs((rsum[i]) - (sum-rsum[i])));
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << diff << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
