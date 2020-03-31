#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0;
    int MAX,MIN;
    int n;
    cin >> n;
    int data[n];

    for (int i = 0; i < n; i++)cin>>data[i];
    
    for (int i = 1; i < n-1; i++){
        MAX=max(max(data[i-1],data[i]),data[i+1]);
        MIN=min(min(data[i-1],data[i]),data[i+1]);

        if(data[i+1]==data[i] || data[i]==data[i-1] || data[i+1]==data[i-1]){
            if(data[i]==MIN)ans++;
        }else{
            if(data[i]!=MAX && data[i]!= MIN)ans++;
        }
    
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
