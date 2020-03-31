#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0,sum=0;
    int n;
    cin >> n;
    int data[n+2]={};
    data[0]=0;
    data[n+1]=0;
    for (int i = 1; i <= n+1; i++){
        cin >>data[i];
        sum += abs(data[i]-data[i-1]); 
    }

    for (int i = 1; i <= n; i++){
        ans = sum - abs(data[i+1]-data[i])-abs(data[i]-data[i-1]) + abs(data[i+1]-data[i-1]);
        cout << ans << '\n';
    }
    
    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;
    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
