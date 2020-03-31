#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=1;
    int n,a;
    int ans=0;

    cin >>n;
    for (int i = 0; i < n; i++){
        cin >>a;
        ans +=(a-1);
    }
    cout << ans <<endl;
    //cout <<fixed<<setprecision(16)<< ans <<endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
