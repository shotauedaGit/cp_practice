#include <bits/stdc++.h>
using namespace std;
    

int main(){
    long long ans=0,sum=0,n,a,b;
    
    cin >>n>>a>>b;

    if(n==1 && a!=b){
        
        ans=0;

    }else if(a > b){
        ans=0;

    }else ans = abs((b*(n-1) + a) - (a*(n-1) + b)) + 1;

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
