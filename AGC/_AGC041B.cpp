#include <bits/stdc++.h>
using namespace std;

#define INF 1001001001
#define LINF 1001001001001001001
#define MOD 1000000007
#define MOD2 998244353

#define all(a)  (a).begin(),(a).end()
#define dig(n)  to_string(n).length()

#define pb push_back
#define eb emplace_back
#define mkp make_pair

#define se second
#define fi first

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,pii> ppii;

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    ll n,m,v,p;
    cin >>n>>m>>v>>p;
    vector<int> a(n);

    for (int i = 0; i < n; i++){
        cin  >> a[i];
    }

    sort(all(a),greater<int>());

    int base = a[p-1];
    ll abp=m*v;

    ans = p;

    for (int i = p; i < n; i++){
        int rem=base - a[i];
        if(abp >= rem){
            abp-=rem;
            ans++;
        }
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
