#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0;
    int k;
    cin >> k;

    if(k%2==0)ans=(k/2)*(k/2);
    else ans=((k+1)/2)*(k/2);

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
