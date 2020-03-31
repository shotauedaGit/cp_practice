#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=1;
    int ans=0,sum=0;
    int n,m;
    
    cin >>n;
    if(n==1){
        cout << "Yes" <<endl;
        return 0;
    }
    int a[n];

    for (int i = 0; i < n; i++){
        cin >>a[i];
    }
    
    //if(a[0] > a[1]+1)flag=0;

    int mx=a[0];
    for (int i = 0; i < n; i++){
        mx = max(mx,a[i]);
        if(mx > a[i] + 1){
            flag=0;
            break;
        }
    }
    


    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    if(flag==1)cout << "Yes" <<endl;
    else cout << "No" <<endl;
    
    return 0;
}
