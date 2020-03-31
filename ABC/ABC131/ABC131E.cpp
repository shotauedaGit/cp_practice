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

    int n,k;
    cin >>n>>k;
    int lim = ((n-1)*(n-2))/2;
    vector<pii> uni;
    vector<pii> es;

    if( k > lim){
        cout << -1 << endl;
        return 0;
    }

    for (int i = 2; i <= n; i++){
        uni.pb(pii(1,i));
    }
    
    for (int i = 2; i < n; i++){
        for (int j = i+1; j <= n; j++){
            es.pb(pii(i,j));
        }
    }

    for (int i = 0; i < lim - k; i++){
        uni.pb(es[i]);
    }

    cout << uni.size() <<endl;
    for (int i = 0; i < uni.size(); i++){
        int a = uni[i].first;
        int b = uni[i].second;

        cout <<a<<" "<<b<<endl;
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
