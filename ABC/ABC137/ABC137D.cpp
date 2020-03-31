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
    map<int,vector<int>> job;
    priority_queue<int> q;

    for (int i = 0; i < n; i++){
        int a,b;
        cin >>a>>b;

        if(a <= m)job[a].push_back(b);
    }
    
    for (int i = 1; i <= m; i++){
        
        if(job[i].size() > 0){
            for (int j = 0; j < job[i].size(); ++j){
                q.push(job[i][j]);
            }
        }
        if(!q.empty()){
            ans += q.top();
            q.pop();
        }
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
