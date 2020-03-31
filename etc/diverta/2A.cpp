#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=1;
    int n,k;
    int ans=0;

    cin >>n>>k;
    if(k==1)ans=0;
    else ans = n-(k-1)-1;
    cout << ans <<endl;
    cout <<fixed<<setprecision(16)<< ans <<endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
