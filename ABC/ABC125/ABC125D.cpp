#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=0;
    int n,a;
    int minus=0,MIN=1e9+1;
    cin >>n;
    int64_t ans=0;

    for (int i = 0; i < n; i++){
        cin >>a;
        if(a<0)minus++;
        ans +=abs(a);
        MIN = min(MIN,abs(a));
    }
    if(minus % 2==1){
        ans -= 2*MIN ;
    }
    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
