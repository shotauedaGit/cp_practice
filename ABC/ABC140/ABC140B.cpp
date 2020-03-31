#include <bits/stdc++.h>
using namespace std;

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
    int a[n],b[n],c[n];

    for (int i = 0; i < n; i++){cin >>a[i]; --a[i];}
    for (int i = 0; i < n; i++){cin >>b[i]; ans += b[i];}
    for (int i = 0; i < n; i++)cin >>c[i];

    for (int i = 0; i < n-1; i++){
        if(a[i+1] == a[i]+1 )ans += c[a[i]];
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
