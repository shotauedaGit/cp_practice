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
    
    int n;
    cin >>n;
    
    vector<ll> a(n);
    for (int i = 0; i < n; i++)cin >>a[i];
    
    sort(all(a));

    int bound=1;
    while(0 > a[bound])++bound;

    for (int i = 0; i < bound; i++)
    {
        ans -= a[i];
    }
    
    for (int i = bound; i < n; i++)
    {
        ans += a[i];
    }
    

    cout << ans << endl;

    int y=0;

    for (int i = n-2; i >= bound; --i)
    {
        y = a[i];

        cout << a[0] << " " << y <<endl;

        a[0] -= y;
    }
    
    
    for (int i = 0; i < bound; ++i)
    {
        y = a[i];

        cout << a[n-1] << " " << y << endl;

        a[n-1] -= y;
    }
    


    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
