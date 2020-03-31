#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0;
    int x,y,z;
    cin >> x>>y>>z;

    while (x>=z){
        x -= y+z;
        ans++;
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans-1 << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
