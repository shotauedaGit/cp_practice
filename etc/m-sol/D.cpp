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

int n;
vector<vector<int>> g;
vector<int> c;
vector<int> v;

void dfs(int s){
    stack<int> st;
    vector<bool> vis(n,false);
    st.push(s);

    int cnt=0;

    while (!st.empty()){
        int cur = st.top();
        st.pop();

        v[cur] = c[cnt];
        ++cnt;
        vis[cur]=true;
        
        for(int i = 0;i < g[cur].size();i++){
            int nex = g[cur][i];
            
            if(vis[nex])continue;
            st.push(nex);
        }
    }
}

int main(){
    bool flag=false;
    ll ans=0,sum=0;

    cin >>n;

    g.resize(n);
    c.resize(n);
    v.resize(n);

    for (int i = 0; i < n-1; i++){
        int a,b;
        cin >>a>>b;
        --a;--b;

        g[a].eb(b);
        g[b].eb(a);
    }

    for (int i = 0; i < n; i++){
        cin >>c[i];
        ans += c[i];
    }

    sort(all(c),greater<int>());
    ans -= c[0];

    dfs(0);

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;
    for(int vi:v)cout << vi << " ";

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
