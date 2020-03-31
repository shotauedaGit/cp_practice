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

    vector<int> d(n);

    for (int i = 0; i < n; i++){
        cin >>d[i];
    }
    
    
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if(i == j)continue;
            ans += d[i]*d[j];
        }
        
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
