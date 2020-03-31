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
    
    int n,m;
    cin >>n>>m;
    vector<pair<bool,int>> prob(n , pair<bool,int>(false,1));
    prob[0] = mkp(true,1);

    bool is1moved=false;
    for (int i = 0; i < m; i++){
        int x,y;
        cin >>x>>y;
        --x;--y;


    prob[y].first = prob[y].first || prob[x].first;

        if(prob[x].second == 1){
            prob[x].first = false;
        }
        prob[y].second += 1;
        prob[x].second -= 1;
    }
    
    for (int i = 0; i < n; i++)
    {
        if(prob[i].first)ans++;
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
