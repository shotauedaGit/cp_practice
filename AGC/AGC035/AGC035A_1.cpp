#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=0;
    int ans=0;
    int n,a;
    int maxbit=0;
    cin >> n;
    int bit[32]={};

    for (int i = 0; i < n; i++){
        cin >>a;
        int j=0;
        while (a>0){
            bit[j] += a%2;
            j++;
            a = a >> 1;
        }
        maxbit=max(j,maxbit);
    }
    
    for (int i = 0; i < maxbit; i++){
        
        if(bit[i]==0  || ){
            flag++;
        }
    }
    

    /*
    for (int i = 0; i < 32; i++){
        cout << bit[i] << " " ;
    }
    */

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;


    if(flag==maxbit)cout << "Yes" <<endl;
    else cout << "No" <<endl;
    
    return 0;
}
