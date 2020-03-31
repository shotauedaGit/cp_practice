#include <bits/stdc++.h>
using namespace std;
    

int main(){
    //int flag=1;
    int a,b,k;
    //int ans=0;
    cin >>a>>b>>k;
    
    if((b-a+1)<2*k){

        for (int i = a; i <= b; i++){
            cout << i <<endl;
        }

    }else{
        for (int i = a; i < a+k; i++){
            cout << i <<endl;
        }
        for (int i = b+(1-k); i <= b; i++){
            cout << i <<endl;
        }
    }

    //cout <<fixed<<setprecision(16)<< ans <<endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
