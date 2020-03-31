#include <bits/stdc++.h>

using namespace std;

#define INF 1001001001  //int32_t
#define MOD 1000000007
#define MOD2 998244353

#define all(a)  (a).begin(),(a).end()

#define pb push_back
#define eb emplace_back
#define mkp make_pair

#define se second
#define fi first

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int n;
    string s;
    cin >>n>>s;

    for (int i = 1; i < n; i++){
        map<char,int> m; int cnt=0;

        for (int j = 0; j < i; j++){
            if(m[s[j]] == 0)++m[s[j]];
        }

        for (int j = i; j < n; j++){
            if(m[s[j]] == 1)++m[s[j]];
        }
        
        for(auto p:m){
            if(p.se == 2)++cnt;
        }

        ans = max((int)ans,cnt);
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
