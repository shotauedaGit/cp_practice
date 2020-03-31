#include <bits/stdc++.h>
using namespace std;


int main(){
    int flag=0;
    int ans=0;
    int i=0;
    string s,t;
    cin >>s>>t;
    int sf[26]={},tf[26]={};

    for (int i = 0; i < s.length(); i++){
        sf[(int)(s[i]-'a')]++;
        tf[(int)(t[i]-'a')]++;
    }

    sort(sf,sf+26,greater<int>());
    sort(tf,tf+26,greater<int>());

    while(1){
        if(sf[i]!=tf[i])break;
        if(i>=25){
            flag=1;
            break;
        }
        i++;
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    if(flag==1)cout << "Yes" <<endl;
    else cout << "No" <<endl;
    
    return 0;
}
