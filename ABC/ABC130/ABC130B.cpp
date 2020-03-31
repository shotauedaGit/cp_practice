#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=1;
    int n,x;
    int ans=0;

    cin >>n>>x;

    int d[n+2],l[n+1];
    
    d[0]=-999;
    d[1]=0;
    ans++;
    
    for (int i = 1; i <= n; i++){
        cin >>l[i];
        d[i+1] = d[i] + l[i];

        if(d[i+1] <= x)ans++;
    }
    
    cout << ans <<endl;
    //cout <<fixed<<setprecision(16)<< ans <<endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
