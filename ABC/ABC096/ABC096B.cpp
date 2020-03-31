#include <bits/stdc++.h>
using namespace std;
    

int main(){
    //int flag=1;
    long long MAX;
    int a,b,c,k;
    long long ans=0;

    cin >>a>>b>>c>>k;
    ans = a+b+c;

    MAX=max(c,max(a,b));
    ans -= MAX;
    MAX <<= k;
    ans +=MAX;

    cout << ans <<endl;
    //cout <<fixed<<setprecision(16)<< ans <<endl;
    
    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
