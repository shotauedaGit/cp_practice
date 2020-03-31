#include <bits/stdc++.h>
#define start 0
#define M 1e9
using namespace std;


int main(){
    int ans=0;
    int u,v;
    int n,m;
    int s,t;
    int MIN=M;

    int p,q,k,j;

    cin >> n;
    int cost[n+1],parent[n+1],visit[n+1];
    vector <vector<int>> adj(n+1);

    for (int i = 0; i < m; i++){
        cin >>u>>v;
        adj[u].push_back(v);
    }
    cin >>s>>t;




    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
