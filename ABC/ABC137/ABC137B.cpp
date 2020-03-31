#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0,sum=0;
    int k,x;
    
    cin >>k>>x;
    int a=x-k+1;

    for (int i = 0; i < 2*k-1; i++){
        cout << a+i << " ";
    }
    


    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
