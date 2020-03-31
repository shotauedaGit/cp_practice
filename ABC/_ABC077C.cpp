#include <bits/stdc++.h>
using namespace std;
    

int main(){
    long long ans=0,sum=0;
    int n;
    cin >> n;
    
    int a[n],b[n],c[n];
    int a2b[n],b2c[n],sumb2c[n];

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        cin >> b[i];
    }

    for (int i = 0; i < n; i++){
        cin >> c[i];
    }

    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);

    /*

    */

    int p=0;
    for (int i = 0; i < n; i++){
        while (b[i] >= c[p])p++;
        b2c[i] = n-p;
    }

    sumb2c[0]=b2c[0];
    for (int i = 1; i < n; i++){
        sumb2c[i]=sumb2c[i-1]+b2c[i];
    }

    p=0;
    for (int i = 0; i < n; i++){
        while (a[i] >= b[p])p++;

        if(p==0){
            a2b[i]=sumb2c[n-1];
        }else{
            a2b[i]=sumb2c[n-1]-sumb2c[p-1];
        }
        sum += a2b[i];
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << sum << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
