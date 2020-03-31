#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag;
    int ans=0;
    int a,b;
    cin >> a>>b;

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    if(a*b%2==0)flag=0;
    else flag=1;

    if(flag==1)cout << "Yes" <<endl;
    else cout << "No" <<endl;
    
    return 0;
}
