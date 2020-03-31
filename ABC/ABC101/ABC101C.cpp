#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=0;
    int n,k;
    int MIN=1e5+1,p=0;
    cin >>n>>k;
    int a[n];
    int ans=0;

    for (int i = 0; i < n; i++){
        cin >>a[i];
        
        if(MIN > a[i]){
            MIN = a[i];
            p=i;
        }
    }
    
    ans = (n+k-3)/(k-1);
    

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
