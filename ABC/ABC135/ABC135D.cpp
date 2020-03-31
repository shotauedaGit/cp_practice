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

    string s,zero="0";
    cin >>s;

    s = to_string(0) + s;

    ll dp[s.size()][13]={};
    dp[0][0] = 1;

    for (int i = 1; i < s.size(); i++){
        for (int j = 0; j < 13; j++){
            
            if(s[i] == '?'){
                for (int ki = 0; ki < 10; ki++){
                    int m = (j*10 + ki)%13;
                    dp[i][m] =(dp[i][m]  + dp[i-1][j])%MOD;
                }
                
            }else{
                int si = (int)(s[i] - '0');
                int m = (j*10 + si)%13;
                dp[i][m] = (dp[i][m] + dp[i-1][j])%MOD;
            }
        }
        
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << dp[s.size()-1][5] << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
