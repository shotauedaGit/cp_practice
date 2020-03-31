#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=0;
    double W,H,x,y;
    int ans=0;

    cin >>W>>H>>x>>y;

    if(x == W/2 && y == H/2)flag=1;

    cout <<fixed<<setprecision(16)<< (W*H/2)<<" ";
    cout << flag << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}