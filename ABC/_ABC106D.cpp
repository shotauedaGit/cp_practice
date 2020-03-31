#include <bits/stdc++.h>
using namespace std;

#define INF ((1<<31)-1)  //int32_t
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
    int n,a;
    cin >>n>>a;
    int x[n];

    for (int i = 0; i < n; i++)
    {
        cin >>x[i];
        sum += x[i];
    }
    
    ll dp[n + 1][sum + 1];
    dp[0][0]=1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            dp[i+1][j+x[i]] += dp[i][j];
            dp[i+1][j] += dp[i][j];
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        if(a*i <= sum)ans += dp[i][a*i];
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
