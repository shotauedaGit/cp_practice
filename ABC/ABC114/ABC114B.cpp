#include <bits/stdc++.h>
using namespace std;
    

int main(){
    string s;
    int num,MIN=999;
    int ans;

    cin >>s;

    for (int i = 0; i < s.length()-2; i++){
        num = 100*(s[i]-'0')  + 10*(s[i+1]-'0') +(s[i+2]-'0');
        if(MIN > abs(753-num)){
            MIN=abs(753-num);
            ans=num;
        }
    }
    //cout << ans <<endl;
    cout << MIN <<endl;
    
    return 0;
}
