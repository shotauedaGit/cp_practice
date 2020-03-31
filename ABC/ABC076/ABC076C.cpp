#include <bits/stdc++.h>

using namespace std;

#define INF 1001001001  //int32_t
#define MOD 1000000007
#define MOD2 998244353

#define all(a)  (a).begin(),(a).end()

#define mkp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    string sd,t;
    cin >>sd>>t;

    int sdl = sd.size();
    int tl = t.size();

    vector<string> sol;

    for (int i = 0; i < sdl; i++){
        bool match=true;
        for (int j = 0; j < tl; j++){
            
            if(sd[i+j]=='?')continue;
            
            if(sd[i+j] != t[j]){
                match = false;
                break;
            }
        }
        
        if(match){
            string tmp = sd;
            tmp.assign(t,i,tl);
            
            puts("tmp");
            sol.emplace_back(tmp);
        }
    }
    
    


    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
