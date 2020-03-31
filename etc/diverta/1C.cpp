#include <bits/stdc++.h>
using namespace std;

int main(){
    int n1=0,n2=0,n3=0;
    int n,ans,len,sum=0;
    string s;

    cin >>n;

    for (int i = 0; i < n; i++){
        cin >>s;
        len=s.length();

        for (int j = 0; j < len-1; j++){
            if(s[j]=='A'&&s[j+1]=='B')sum++;
        }

        if(s[0]=='B' && s[len-1]=='A'){
            n3++;
        }else if(s[len-1]=='A'){
            n1++;
        }else if(s[0]=='B'){
            n2++;
        }
    }

    if(n3>0){
        if(n2>0 && n1>0){
            ans = sum + n3 + min(n1-1,n2-1) + 1;
        }else if(n1>0 || n2>0){
            ans = sum + n3;
        }else{
            ans =sum + n3 -1;
        }
    }else{
        if(n2>0 && n1>0){
            ans = sum + min(n1,n2);
        }else{
            ans = sum;
        }
    }



    //cout << ans <<endl;
    cout << ans <<endl;
    
    return 0;
}
