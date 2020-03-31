#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0,sum=0;
    int n;
    
    cin >>n;
    double a[n];

    for (int i = 0; i < n; i++){
        cin >>a[i];
    }
    
    sort(a,a+n);

    for (int i = 1; i < n; i++){
        a[i]=(a[i-1]+a[i])/2;
    }
    


    cout <<fixed<<setprecision(16)<< a[n-1]<< endl;
    //cout << a[n-1] << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
