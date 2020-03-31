#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int a,b;
    int flag=0;
    int n;
    int ans=0;

    cin >>a>>b;

    if(b<10){
        a *= 10;
    }else if(b<100){
        a *= 100;
    }else{
        a *= 1000;
    }

    if(sqrt(a+b) == (int)sqrt(a+b))flag=1;
    
    //cout << ans <<endl;
    //cout <<fixed<<setprecision(16)<< ans <<endl;

    if(flag==1)cout << "Yes" <<endl;
    else cout << "No" <<endl;
    
    return 0;
}
