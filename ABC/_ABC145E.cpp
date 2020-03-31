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

    int n,t;
    cin >>n>>t;

    vector<pii> ba;
    map<int,int> lo;
    int dp[3005][3005]={};

    for (int i = 0; i < n; i++){
        int ai,bi;
        cin >>ai>>bi;
        ba.emplace_back(ai,bi);
    }

    sort(all(ba));

    for (int i = 1; i < n; i++){
        for (int j = 0; j < t; j++){
            if(j > ba[i-1].fi)dp[i][j]=max(dp[i-1][j],dp[i-1][j-ba[i-1].fi] + ba[i-1].se);
            else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }


    
    /*for (int j = 0; j < t; j++){
        for (int i = 0; i <= n; i++){
            printf("%3d",dp[i][j]);
        }
        puts("");
    }*/
    

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << dp[n-1][t-1]  + ba[n-1].se << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
