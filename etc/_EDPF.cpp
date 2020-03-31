#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0,sum=0;
    int n,m;
    string s,t;
    string LCS="";

    cin >>s>>t;

    string dp[s.size()+1][t.size()+1];
    dp[0][0]="";

    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < t.size(); j++){
            
            if(s[i]==t[j]){

                dp[i+1][j+1] = dp[i][j];
                dp[i+1][j+1].append(s,i,1);


            }else{
                if(dp[i+1][j].size() >= dp[i][j+1].size()){
                    dp[i+1][j+1]=dp[i+1][j];
                }else{
                    dp[i+1][j+1]=dp[i][j+1];
                }
            }
        }
    }
    


    //cout <<fixed<<setprecision(16)<< << endl;
    cout << dp[s.size()][t.size()] << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
