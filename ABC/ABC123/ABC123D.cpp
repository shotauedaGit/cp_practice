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
    
    int x,y,z,k;
    cin >>x>>y>>z>>k;
    vector<ll> a(x),b(y),c(z);
    vector<ll> ab,abc;

    for (int i = 0; i < x; i++)cin >>a[i];
    for (int i = 0; i < y; i++)cin >>b[i];
    for (int i = 0; i < z; i++)cin >>c[i];

    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            ab.emplace_back(a[i]+b[j]);
        }
    }
    sort(all(ab),greater<ll>());

    for (int i = 0; i < min(k,(int)ab.size()); i++){
        for (int j = 0; j < z; j++){
            abc.emplace_back(ab[i]+c[j]);
        }
    }
    sort(all(abc),greater<ll>());

    for (int i = 0; i < min(k,(int)abc.size()); i++){
        cout << abc[i] <<endl;
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
