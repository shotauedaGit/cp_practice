#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag;
    int a,b,c;
    int ans=0;

    cin >>a>>b>>c;
    
    if(a+b >= c)flag=1;
    else flag=0;

    //cout << ans <<endl;
    //cout <<fixed<<setprecision(16)<< ans <<endl;

    if(flag==1)cout << "Yes" <<endl;
    else cout << "No" <<endl;
    
    return 0;
}
