#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int n,q;

    
    cin >>n>>q;
    vector<vector<int>> adj(n+1);
    bool visit[n+1];
    int px[n+1]={};

    for (int i = 0; i < n-1; i++){
        visit[i]=false;
        
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    visit[n-1]=false;visit[n]=false;
    
    for (int i = 0; i < q; i++){
        int p,x;
        cin >>p>>x;
        px[p] += x;
    }
    

    queue<int> que;
    que.push(1);

    while(que.size()){
        int cur=que.front();
        visit[cur]=true;
        que.pop();

        //cout << cur<<"::"<<px[cur]<< endl;//

        for (int j = 0; j < (int)adj[cur].size(); j++){
            

            int nex=adj[cur][j];
            if(visit[nex]==true)continue;


            px[nex] += px[cur];

            que.push(nex);

            //cout << cur<<"--"<<nex<< endl;//
        }
        

    }


    for (int i = 1; i <= n; i++){
        cout << px[i] << " ";
    }
    std::cout << '\n';


    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
