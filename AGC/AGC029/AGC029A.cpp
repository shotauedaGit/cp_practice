#include <bits/stdc++.h>
using namespace std;
    

int main(){
    long long ans=0,sum=0;
    string s;
    cin >>s;

    for (int i = s.length()-1; i >= 0; --i){
        if(s[i]=='W')sum++;
        else ans += sum;
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
