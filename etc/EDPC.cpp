#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0,sum=0;
    int n,m;
    
    cin >>n;
    int a[n],b[n],c[n];
    int dp[n][3];

    for (int i = 0; i < n; i++){
        cin >>a[i]>> b[i]>> c[i];
    }
    
    dp[0][0]=a[0];
    dp[0][1]=b[0];
    dp[0][2]=c[0];

    for (int i = 1; i < n; i++){
        
        dp[i][0]= max(dp[i-1][1] + a[i] , dp[i-1][2] + a[i]);
        dp[i][1]= max(dp[i-1][0] + b[i] , dp[i-1][2] + b[i]);
        dp[i][2]= max(dp[i-1][0] + c[i] , dp[i-1][1] + c[i]);
    }
    


    //cout <<fixed<<setprecision(16)<< << endl;
    cout << max(max(dp[n-1][0],dp[n-1][1]),dp[n-1][2]) << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
