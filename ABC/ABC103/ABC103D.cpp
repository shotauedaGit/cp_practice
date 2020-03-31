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

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int main(){

    bool flag=true;

    ll ans=0,sum=0;
    int prebridge = -1;

    int n,m;
    cin >>n>>m;
    
    vector<pii> vs(m);

    for (int i = 0; i < m; i++){
        int a,b;
        cin >>a>>b;
        --b,--a;
        vs[i].first=b;
        vs[i].second=a;
    }
    
    sort(vs.begin(),vs.end());

    int a,b;
    for (int i = 0; i < m; i++){
        a = vs[i].second;
        b = vs[i].first;
        
        if(a >= prebridge){
            ++ans;
            prebridge = b;

            //cout << b << endl;
        }
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
