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

ll gcd(ll m,ll n){
    if(n == 0)return m;
    else if(m>n){return gcd(n,m%n);
    }else{return gcd(m,n%m);}}

ll lcm(ll m,ll n){return m*n/gcd(m,n);}

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    ll a,b;
    cin >>a>>b;

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << lcm(a,b) << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
