#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll GCD(ll m,ll n){
    ll big,small;
    ll p=-1;
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
    ll ans=1,sum=0;
    ll t;
    int n,m;
    cin >>n;
    ll data[n];
    
    for (int i = 0; i < n; i++){
        cin >>data[i];
    }
    
    sort(data,data+n);
    ans=data[0];

    for (int j = 0; j < n-1; j++){

        if(data[j+1]%ans == 0){

            ans = data[j+1];
            
        }else{

            ll temp = ans;
            ans = temp/GCD(data[j+1],ans);
            ans *= data[j+1];

        }

    }
    


    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}