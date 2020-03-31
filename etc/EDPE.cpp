#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0,sum=0;
    int n,W;
    int sumV=0,maxV=0;
    
    cin >>n>>W;
    
    int w[n+1],v[n+1];
    
    w[0]=0;
    v[0]=0;
    
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
        sumV += v[i];
    }
    
    int dp[sumV+1][n+1];
    
    for (int i = 0; i < sumV+1; i++) {
        for (int j = 0; j < n+1; j++) {
            
            dp[i][j]=W+1;
            
        }
    }
    dp[0][0]=0;

    for (int i = 0; i < sumV+1; i++) {
        for (int j = 1; j < n+1; j++) {
            
            if(i-v[j] >= 0){
                
                dp[i][j]=min(dp[i-v[j]][j-1] + w[j],dp[i][j-1]);
            }else{
                dp[i][j]=dp[i][j-1];
            }
            if(dp[i][j] <= W){
                maxV=max(i,maxV);
            }
            
        }
    }


    //cout <<fixed<<setprecision(16)<< << endl;
    cout << maxV << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
