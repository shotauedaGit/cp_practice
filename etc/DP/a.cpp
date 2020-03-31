#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0,sum=0;
    int n,x;
    
    cin >>n>>x;
    int dp[n][x+1];
    int a[n];

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    


    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
