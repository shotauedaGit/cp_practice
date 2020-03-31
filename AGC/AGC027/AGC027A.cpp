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

    int n,x;
    cin >>n>>x;
    vector<int> a(n);

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(all(a));
    
    
    int i=0;
    while (x > 0){
        x -= a[i++];
        ++ans;
        if(i >= n)break;
    }
    
    if(x != 0)--ans;

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
