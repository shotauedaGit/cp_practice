#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0;
    int n,a,b;
    cin >> n >> a>>b;
    int data[n];

    //cout <<fixed<<setprecision(16)<< << endl;
    if(n*a>b)cout << b << endl;
    else cout << n*a << '\n';

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
