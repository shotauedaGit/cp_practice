#include <bits/stdc++.h>
using namespace std;
    

int main(){
    long long ans=0,sum=0;
    string s;
    
    cin >>s;
    int n=s.length();

    for (int i = 0; i < n; i++){
        if(s[i]=='U'){
            ans += 2*i + (n-i-1);
        }else{
            ans += 2*(n-i-1) + i;
        }
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
