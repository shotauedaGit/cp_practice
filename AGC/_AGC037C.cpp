#include <bits/stdc++.h>
using namespace std;
    

int main(){
    long long ans=0,sum=0;
    int n;
    
    cin >>n;
    int a[n],b[n];

    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++)cin >> b[i];

    while(true){
        bool flag=true;
        bool quit=true;

        for (int i = 0; i < n; i++){
            int l=i-1,r=i+1;

            if(i==0){
                l=n-1;
            }else if(i==n-1){
                r=0;
            }else{
                l=i-1;
                r=i+1;
            }

            if(b[i]!=a[i])flag=false;
            if(b[i] > b[l]+b[r])quit=false;

            ans += b[i]/(b[l]+b[r]);
            b[i] %= (b[l]+b[r]);
            
            if(a[i] > b[i]){
                int sub=(a[i]-b[i]+(b[l]+b[r]-1))/(b[l]+b[r]);
                ans -= sub;
                b[i] += sub*(b[l]+b[r]);
            }

        }
        
        if(flag){
            cout << ans << endl;
            break;
        }else if(quit){
            cout << "-1" << endl;
            break;
        }

    }


    //cout <<fixed<<setprecision(16)<< << endl;
    

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
