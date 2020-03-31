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

    int n;
    map<int,int> m;
    cin >>n;

    for (int i = 0; i < n; i++){
        int a;
        cin >>a;

        ++m[a];
        m[a] %= 2;
    }

    for(auto p : m){
        if(p.second == 1)ans++;
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
