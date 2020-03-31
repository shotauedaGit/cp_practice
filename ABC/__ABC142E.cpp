#include <bits/stdc++.h>

using namespace std;

#define INF 100001  //int32_t
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

    int ans=INF,sum=0;
    
    int n,m;
    cin >>n>>m;
    
    vector<pii> keys(m);

    for (int i = 0; i < m; i++){
        int a,b;
        int bit=0;
        cin >>a>>b;

        for (int j = 0; j < b; j++){
            int k;
            cin >>k;
            bit += 1<<(k-1);
        }
        
        keys[i] = pii(a,bit);
    }

    vector<vector<int>> dp(1<<n,vector<int>(m+1,INF));
    for(int i=0;i<=m;++i)dp[0][i]=0;


    for (int j = 1; j <= m; j++){
        for (int i = 0; i < (1<<n); i++){

            int newbit = i | keys[j-1].second;
            cout <<i<<" || "<<keys[j-1].second<<"="<<newbit<< endl;

            cout <<dp[newbit][j-1]<<"  < or >  "<<dp[i][j-1]<<"+"<<keys[j-1].first<< endl;

            dp[newbit][j] = min( dp[newbit][j-1] , dp[i][j-1]+keys[j-1].first );

            cout << "dp"<<newbit<<"_"<<j<<" = "<<dp[newbit][j]<< endl;
        }
        
    }


    puts("");
    for (int i = 0; i < (1<<n); i++){
        bitset<4> b = i;
        cout << b <<"   ";
        
        for (int j = 0; j <= m; j++){
            if(dp[i][j]!= INF)printf("%4d ",dp[i][j]);
            else printf(" INF ");
        }
        puts("");
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    
    if(ans == INF)cout << -1 << endl;
    else cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
