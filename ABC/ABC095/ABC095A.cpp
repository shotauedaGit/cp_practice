#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=1;
    string s;
    int ans=700;

    cin >>s;

    if(s[0]=='o')ans+=100;
    if(s[1]=='o')ans+=100;
    if(s[2]=='o')ans+=100;
    
    cout << ans <<endl;
    //cout <<fixed<<setprecision(16)<< ans <<endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
