#include <bits/stdc++.h>
using namespace std;
    

int main(){
    string s,t;
    int flag=0;
    int count=0;
    
    cin >>s>>t;

    for (int i = 0; i < s.length(); i++){
        for (int j = 0; j < t.length(); j++){
            if(s.compare(i,1,t,j,1) < 0)flag=1;
            else if(s.compare(i,1,t,j,1)==0){
                count++;
            }
        }
    }


    if(flag==0 && count==(s.length()*t.length())){
        if(s.length()<t.length())flag=1;
    }
    //cout << ans <<endl;
    //cout <<fixed<<setprecision(16)<< ans <<endl;

    if(flag==1)cout << "Yes" <<endl;
    else cout << "No" <<endl;
    
    return 0;
}
