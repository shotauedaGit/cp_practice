#include <bits/stdc++.h>
using namespace std;
    

int main(){
    bool flag=true;
    double ans=0,sum=0;
    int n;
    cin >>n;
    vector<pair<double,pair<int,int>>> dp(n+1);

    dp[0]=make_pair(0.0,make_pair(0,0));
    int x,y;

    for (int i = 0; i < n; i++){
        cin>>x>>y;
        long long nx=dp[i].second.first + x;
        long long ny=dp[i].second.second + y;
        double dis = dp[i].first;
        double ndis = sqrt((long long)(nx*nx + ny*ny));

        //cout << "x,y=" <<nx<<" "<<ny<< " ndis:"<<ndis<<'\n';

        if(ndis > dis){
            dp[i+1]=make_pair(ndis,make_pair(nx,ny));
        }else{
            dp[i+1]=dp[i];
        }
    }
    


    cout <<fixed<<setprecision(16)<<dp[n].first<< endl;
    //cout <<  << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
