#include <bits/stdc++.h>
using namespace std;
    

int main(){
    long long ans=0,sum=0;
    int n,m;
    cin >> n;
    
    int a[n+1],b[n];

    for (int i = 0; i < n+1; i++){
        cin >>a[i];
    }

    for (int i = 0; i < n; i++){
        cin >>b[i];
    }


    if(n%2==0){

        for(int i = 0; i < (n+1)/2; i++){
            int t=min(b[i],a[i]);
            a[i] -=t;
            b[i] -=t;
            ans += t;

            int t1=min(b[i],a[i+1]);
            a[i+1] -= t1;
            ans += t1;
            b[i] -= t1;

            int t2=min(b[n-1-i],a[n-i]);
            a[n-i] -=t2;
            b[n-1-i] -=t2;
            ans += t2;

            int t3=min(b[n-1-i],a[n-i-1]);
            a[n-1-i] -= t3;
            ans += t3;
            b[n-1-i] -= t3;

        }

    }else{

        for(int i = 0; i < n/2 ; i++){

            int t=min(b[i],a[i]);
            a[i] -=t;
            b[i] -=t;
            ans += t;

            int t1=min(b[i],a[i+1]);
            a[i+1] -= t1;
            ans += t1;
            b[i] -= t1;

            int t2=min(b[n-1-i],a[n-i]);
            a[n-i] -=t2;
            b[n-1-i] -=t2;
            ans += t2;

            int t3=min(b[n-1-i],a[n-i-1]);
            a[n-1-i] -= t3;
            ans += t3;
            b[n-1-i] -= t3;

        }

        ans += min(b[n/2],a[n/2]+a[(n/2)+1]);
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
