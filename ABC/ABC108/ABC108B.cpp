#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0;
    int x1,x2,y1,y2;
    int a;
    cin >> x1>>y1>>x2>>y2;

    int vx = x2 - x1;
    int vy = y1 - y2;

    cout << x2 + vy <<" "<< y2 + vx <<" "<< x1 + vy <<" "<< y1 + vx << endl;
    //cout <<fixed<<setprecision(16)<< << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
