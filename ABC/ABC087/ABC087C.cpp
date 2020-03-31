#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int n = 0;
    cin >> n;
    int a[2][n],sum=0,MAX=0;
    int flag=0,p;
    int ans=0;

    for (int i = 0; i < n; i++)cin >> a[0][i];
    for (int i = 0; i < n; i++)cin >> a[1][i];

    for (int i = 0; i < n; i++){
        ans=0;
        for (int j = 0; j <= i; j++){
            ans += a[0][j];
        }
        for (int j = i; j < n; j++){
            ans += a[1][j];
        }
        
        MAX=max(ans,MAX);
    }
    ans=MAX;

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
