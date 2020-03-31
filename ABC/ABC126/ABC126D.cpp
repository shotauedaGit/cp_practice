#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0;
    int n,q;
    cin >>n;
    vector<vector<pair<int,int>>> adj(n);
    bool visit[n];
    int color[n];
    color[0]=0;

    for (int i = 0; i < n-1; i++){
        visit[i]=false;
        
        int u,v,w;
        cin>>u>>v>>w;
        --u;--v;

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    visit[n-1]=false;


    queue<int> que;
    que.push(0);

    while(que.size()){
        int cur=que.front();
        visit[cur]=true;
        que.pop();

        //cout << cur<<"::"<<px[cur]<< endl;//

        for (int j = 0; j < (int)adj[cur].size(); j++){
            

            int nex=adj[cur][j].first;
            if(visit[nex]==true)continue;

            //begin

            if(adj[cur][j].second % 2 == 1){

                color[nex] = (color[cur]+1)%2;
            
            }else{

                color[nex] = color[cur];
            
            }

            //end

            que.push(nex);

            //cout << cur<<"--"<<nex<< endl;//
        }
        

    }

    for (int i = 0; i < n; i++){
        cout << color[i] << '\n';
    }
    




    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
