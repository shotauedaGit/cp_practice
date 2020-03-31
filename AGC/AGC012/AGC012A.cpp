#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=1;
    int n;
    long long ans=0;
    int num=0,j=0;

    cin >>n;
    int data[3*n];
    
    for (int i = 0; i < 3*n; i++){
        cin >>data[i];
    }
    sort(data,data+3*n,greater<int>());

    while(num < n){
        if(j%2 == 1){
            ans += data[j];
            num++;
        }
        j++;
    }
    
    cout << ans <<endl;
    
    //cout <<fixed<<setprecision(16)<< ans <<endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
