#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0,sum=0;
    int a,b;
    
    cin >>a>>b;

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << max(a*b,max(a-b,a+b)) << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
