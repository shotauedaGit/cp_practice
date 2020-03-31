#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag;
    int n,p,sn=0;
    int ans=0;

    cin >>n;
    p=n;

    while (p>0){
        sn += (p%10);
        p /= 10;
    }

    if(n % sn ==0)flag=1;
    else flag=0;
    
    //cout << ans <<endl;
    //cout <<fixed<<setprecision(16)<< ans <<endl;

    if(flag==1)cout << "Yes" <<endl;
    else cout << "No" <<endl;
    
    return 0;
}
