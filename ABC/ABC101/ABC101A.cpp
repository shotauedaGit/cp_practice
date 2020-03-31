#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int n = 0;
    string s;
    cin >> s;
    int flag=0;
    int ans=0;

    for (int i = 0; i < 4; i++){
        if(s[i]=='+')ans++;
        else ans--;
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
