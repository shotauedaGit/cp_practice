#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int n = 0;
    string s;
    int flag=0;
    int a=0,b=0,c=0;
    cin >> s;

    for (int i = 0; i < s.length(); i++){
        if(s[i]=='a')a++;
        if(s[i]=='b')b++;
        if(s[i]=='c')c++;
    }
    if(a==1 && b==1 && c==1)flag=1;

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    if(flag==1)cout << "Yes" <<endl;
    else cout << "No" <<endl;
    
    return 0;
}
