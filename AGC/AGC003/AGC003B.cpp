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
    
    int n;
    cin >>n;

    vector<ll> a(n);
    vector<int> mod2(n);

    for (int i = 0; i < n; i++)
    {
        int ai;
        cin >>ai;

        a[i] = ai;
        mod2[i] = ai % 2;
    }

    for (int i = 0; i < n; i++)
    {
        if(i+2 < n && mod2[i]==1 && mod2[i+2]==1 && mod2[i+1]==0){
            ans += (a[i]+a[i+1]+a[i+2])/2;
            i += 2;
        }else if(i+1 < n && mod2[i]==1 && mod2[i+1]==1){
            ans += (a[i]+a[i+1])/2;
            i++;
        }else{
            ans += a[i]/2;
        }
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
