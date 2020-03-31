#include <bits/stdc++.h>
using namespace std;
    
int GCD(int m,int n){
    int big,small;
    int p=-1;
    big=max(m,n);
    small=min(m,n);

    while(1){
        p=big%small;
        if(p==0)break;
        big=small;
        small=p;
    }
    
    return small;
}

int main(){
    int ans=0,sum=0;
    int n;
    
    cin >>n;
    int a[n];
    int toi[n];
    int fromiton[n];


    cin >>a[0];
    for (int i = 1; i < n; i++){
        cin >>a[i];
    }

    toi[0]=a[0];
    fromiton[n-1]=a[n-1];
    
    for (int i = 1; i < n; i++){
        toi[i] =GCD(a[i],toi[i-1]);
        fromiton[n-i-1]=GCD(a[n-i-1],fromiton[n-i]);
    }

    ans=max(ans,fromiton[1]);
    
    for (int i = 0; i < n-2; i++){
        ans=max(ans,GCD(toi[i],fromiton[i+2]));
    }    
    ans = max(ans,toi[n-2]);
    



    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
