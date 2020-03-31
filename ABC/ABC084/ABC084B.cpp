#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=1;
    int ans=0,i=0;
    int a,b;
    string s;
    cin >>a>>b>>s;

    while (i<a){
        if((s[i]-'0')>=10 ||(s[i]-'0')<0){
            flag=0;
        }
        i++;
    }
    if(s[i++]!='-')flag=0;
    while (i<a+b+1){
        if((s[i]-'0')>=10 ||(s[i]-'0')<0){
            flag=0;
        }
        i++;
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    if(flag==1)cout << "Yes" <<endl;
    else cout << "No" <<endl;
    
    return 0;
}
