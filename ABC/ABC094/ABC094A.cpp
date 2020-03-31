#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int n = 0;
    int a,b,x;
    cin >> a>>b>>x;
    
    int flag=0;
    int ans=0;

    if(a>x)flag=0;
    else{
        if(b-1 >= x-a)flag=1;
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    if(flag==1)cout << "YES" <<endl;
    else cout << "NO" <<endl;
    
    return 0;
}
