#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int n = 0,a;
    cin >> n>>a;
    
    int flag=0;
    int ans=0;

    if(n%500 <= a)flag=1;

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    if(flag==1)cout << "Yes" <<endl;
    else cout << "No" <<endl;
    
    return 0;
}
