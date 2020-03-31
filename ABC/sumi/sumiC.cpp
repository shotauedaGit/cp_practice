#include <bits/stdc++.h>

using namespace std;

#define INF 1001001001
#define LINF 1001001001001001001
#define MOD 1000000007
#define MOD2 998244353

#define all(a)  (a).begin(),(a).end()
#define dig(n)  to_string(n).length()

#define pb push_back
#define eb emplace_back
#define mkp make_pair

#define se second
#define fi first

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,pii> ppii;

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int x;
    cin >>x;
    vector<bool> dp(x+1);
    fill(all(dp),false);

    dp[100]=true;
    dp[101]=true;
    dp[102]=true;
    dp[103]=true;
    dp[104]=true;
    dp[105]=true;

    for (int i = 0; i <= x; i++){
        for (int j = 100; j <= 105; j++){
            if(dp[i] && i+j<=x)dp[i+j]=true;
        }
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << dig(n) << endl;

    if(dp[x])cout << "1" <<endl;
    else cout << "0" <<endl;
    
    return 0;
}
