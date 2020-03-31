#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0,sum=0;
    long long k;
    string s;
    cin >>s>>k;
    
    int i=0;
    while (s[i]=='1')i++;

    if(k < i+1){
        cout << "1" << endl;
    }else{
        cout << s[i] << endl;
    }
    
    


    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
