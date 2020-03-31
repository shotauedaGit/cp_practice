#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=0;
    int x,p,fx=0;
    int ans;

    cin >>x;
    p=x;
    while (p>0){
        fx += (p%10);
        p /= 10;
    }
    
    if(x%fx==0)flag=1;
    //cout << ans <<endl;
    //cout <<fixed<<setprecision(16)<< ans <<endl;

    if(flag==1)cout << "Yes" <<endl;
    else cout << "No" <<endl;
    
    return 0;
}
