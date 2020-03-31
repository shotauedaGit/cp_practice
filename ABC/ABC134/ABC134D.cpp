#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0,sum=0;
    int n;
    cin >> n;
    
    int a[n];
    int box[n];
    int anslist[n];

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    for (int i = n; i >= 1; i--){
        
        int k=2;
        int bit = a[i-1];
        
        while (k*i <= n){
            bit ^= box[k*i-1];
            k++;
        }
        box[i-1]=bit;
    }
    
    for (int i = 0; i < n; i++){
        if(box[i]==1){
            anslist[ans]=i+1;
            ans++;
        }
    }

    cout << ans << endl;
    
    for (int i = 0; i < ans; i++)
    {
        cout << anslist[i] << '\n';
    }
    


    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
