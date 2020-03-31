#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=0;
    int n=0,p;
    string s,t;
    int ans=0;

    cin >>s>>t;

    for (int i = 0; i < s.length(); i++){
        n=0;
        for (int j = 0; j < s.length(); j++){
            
            p=(i+j)%s.length();
            
            if(s[p]==t[j])n++;
        }
        if(n==s.length())flag=1;
        
    }
    
    
    //cout << ans <<endl;
    //cout <<fixed<<setprecision(16)<< ans <<endl;

    if(flag==1)cout << "Yes" <<endl;
    else cout << "No" <<endl;
    
    return 0;
}
