#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0;
    int n,d,x,ai;
    cin >> n >>d>>x;

    for (int i = 0; i < n; i++){
        cin >>ai;
        ans += (d+ai-1)/ai;
    }
    ans += x;
    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
