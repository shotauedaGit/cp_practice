#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0;
    int n,p=9,q=1;
    
    cin >>n;

    if(n < 10){
        ans = n;
    }else if(n < 1000){
        ans = 9 + max(0,n-99);
    }else if(n < 100000){
        ans = 9 + 900 + max(0,n-9999);
    }else{
        ans = 90909;
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
