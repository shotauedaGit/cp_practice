#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int n;
    string s;
    double money,rate=380000.0,ans;
    cin >>n;
    while (n-->0){
        cin >>money>>s;
        if(s=="BTC")ans +=money*rate;
        else ans +=money;
    }
    

    cout <<fixed<<setprecision(10)<< ans <<endl;
    return 0;
}
