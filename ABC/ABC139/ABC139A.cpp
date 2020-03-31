#include <bits/stdc++.h>
using namespace std;
    

int main(){
    bool flag=true;
    long long ans=0,sum=0;
    string s,t;
    cin >>s>>t;
    

    for (int i = 0; i < 3; i++){
        if(s[i]==t[i])ans++;
    }
    


    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
