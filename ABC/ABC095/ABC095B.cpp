#include <bits/stdc++.h>
using namespace std;
    

int main(){
    //int flag=1;
    int n,x,m;
    int MIN=1001;
    int ans=0;

    cin >>n>>x;

    for (int i = 0; i < n; i++){
        cin >>m;

        ans++;
        x-=m;
        
        MIN=min(MIN,m);
    }

    while(1){
        x -= MIN;
        if(x<0)break;
        ans++;
    }
    
    cout << ans <<endl;
    //cout <<fixed<<setprecision(16)<< ans <<endl;
    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
