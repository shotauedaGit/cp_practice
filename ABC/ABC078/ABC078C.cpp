#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int n,m;
    cin >> n >>m;
    int ans = (2<<(m-1))*(100*(n-m) + 1900*m);
    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;
    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
