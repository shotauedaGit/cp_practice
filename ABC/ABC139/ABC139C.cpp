#include <bits/stdc++.h>
using namespace std;
    

int main(){
    bool flag=true;
    int ans=0,sum=0;
    int n;
    cin >>n;
    int a[n],row=0;

    cin >>a[0];
    for (int i = 1; i < n; i++){
        cin >> a[i];

        if(a[i-1] >= a[i]){
            row++;
        }else{
            row=0;
        }

        ans = max(row,ans);
    }
    


    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
