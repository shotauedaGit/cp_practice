#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0;
    int a,b,c;
    cin >> a>>b>>c;

    ans = a+b+c+9*max(a,max(b,c));
    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
