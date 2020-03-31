#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0,sum=0;
    int m,d;
    
    cin >>m>>d;


    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= d; j++){
            
            if(j%10 >= 2 && (j/10) >= 2 && (j%10)*(j/10)==i)ans++;
        }
        
    }
    
    


    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
