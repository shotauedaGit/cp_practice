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
    int n;
    string s;
    cin >>n>>s;
    //vector<vector<int>> diff(n);

    int dp[n][n];

    for (int i = n-1; i >= 0; --i){
        for (int j = n-1; j >= 0; --j){
            if(s[i]==s[j]){

                if(i+1 <= n-1  && j+1 <= n-1){
                    dp[i][j] = dp[i+1][j+1] + 1;
                }else{
                    dp[i][j]=1;
                }

            }else{
                dp[i][j]=0;
            }

            ans = max((ll)min(dp[i][j],abs(i-j)),ans);
        }

    }
    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
