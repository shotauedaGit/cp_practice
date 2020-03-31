#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0,sum=0;
    int a,b,c;
    
    cin >>a>>b>>c;


    //cout <<fixed<<setprecision(16)<< << endl;
    cout << c - min(a,b+c) + b << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
