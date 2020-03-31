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
    int MIN=1e9+1;
    int ans=0;
    int n,x,xi;

    cin >> n>>x;
    cin >>xi;
    ans=abs(x-xi);
    for (int i = 1; i < n; i++){
        cin >> xi;
        ans = GCD(ans,abs(x-xi));
    }
    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
