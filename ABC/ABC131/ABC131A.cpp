#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int n = 0;
    string s;
    cin >> s;
    
    int flag=0;
    int ans=0;

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    for (int i = 1; i < 4; i++){
        if(s[i-1]==s[i])flag=1;
    }
    


    if(flag==1)cout << "Bad" <<endl;
    else cout << "Good" <<endl;
    
    return 0;
}
