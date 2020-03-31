#include <bits/stdc++.h>
using namespace std;
    

int main(){
    long long ans=0,sum=0;
    int n;
    long long A=0,B=0;
    cin >> n;
    
    int a[n];

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a,a+n,greater<int>());
    

    for (int i = 0; i < n-1; i++){
        
        if(a[i]==a[i+1]){
            A=a[i];
            
            i+=2;

            for (int j = i; j < n-1; j++){
                
                if(a[j]==a[j+1]){
                    B=a[j];
                    break;
                }
            }

            break;
        }
    }
    
    

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << A*B << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
