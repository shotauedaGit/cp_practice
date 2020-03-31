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

struct stf{
    ll w;
    int v;
};

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int n,w;
    cin >>n;
    vector<stf> st(n);
    int dp[105][405]={};

    for (int i = 0; i < n; i++)
    {
        int w,v;
        cin >>w>>v;
        st[i] = {w,v};
    }

    dp[1][0] = st[0].v;

    for (int i = 1; i < n; i++){
        for (int j = 0; j <= 3*n; j++){

            int m = (st[i].w)%(st[0].w)+1;
            ll wait = (i+1)*st[0].w + j;

            if(j > m ||  wait <= w){
                dp[i][j] = max(dp[i-1][j - m]+st[i].v , dp[i-1][j] ); 
            }else{
                dp[i][j]=dp[i-1][j];
            }

        }
    }

    for (int j = 0; j < 3*n; j++){
        for (int i = 0; i < n; i++){
            cout << " "<<dp[i][j];
        }
        puts("");
    }
    
    
    

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
