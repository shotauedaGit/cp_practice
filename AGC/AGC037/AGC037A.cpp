#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0,sum=0;
    bool skip=false;
    int n,m;
    string s;
    cin >>s;
    
    ans++;
    for (int i = 1; i < s.length(); i++){

        if(skip){

            ans++;

        }else{

            if(s[i-1]==s[i]){
                skip=true;
                
                if(i == s.length()-1){
                    break;
                }else {
                    i++;
                }
                ans++;

                continue;
            }else{
                ans++;
            }
        
        }
        skip=false;
    }
    


    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
