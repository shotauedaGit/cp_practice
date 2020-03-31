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
    
    int n,m;
    cin >>n>>m;
    vector<int> able(n+1);
    vector<vector<int>> ks(m);
    vector<pii> ka(m);

    for (int i = 0; i < m; i++){
        int a,b;
        cin >>a>>b;

        ka[i] = pii(a,i);
        sum += a;

        for (int j = 0; j < b; j++){
            int cij;
            cin >>cij;
            ks[i].pb(cij);
            
            able[cij]++;
        }
    }
    
    for (int i = 1; i <= n; i++){
        if(able[i] == 0){
            cout << "-1" << endl;
            return 0;
        }
    }
    
    sort(all(ka),greater<pair<int,int>>());

    vector<int> bound(m);
    for (int i = 0; i < m; i++){
        bound[i] = ka[i].first;
    }
    


    for (int i = 0; i < m; i++){
        bool f = true;
        int p = ka[i].second;
        int ai = ka[i].first;
        for (int j = 0; j < ks[p].size(); j++)if(able[ks[p][j]] <= 1)f = false;

        if(f){
            //cout << "key " << p+1 << " is del (a=)" <<ai<<endl; 
            sum -= ai;
            for (int j = 0; j < ks[p].size(); j++)able[ks[p][j]]--;
        }
        
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << sum << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
