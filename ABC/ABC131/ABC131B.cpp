#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int n,l,add;
    cin >> n >>l;
    int MIN=10000;
    int flag=0;
    int ans=0;

    //cout <<fixed<<setprecision(16)<< << endl;

    for (int i = 1; i <= n; i++){
        ans += l+i-1;
        if(MIN > abs(l+i-1)){
            MIN = abs(l+i-1);
            add= l+i-1;
        }

    }
    ans -= add;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
