#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int n,p;
    int ans=0,m=0;

    cin >>n;

    for (int i = 0; i < n; i++){
        cin >> p;
        ans+=p;
        m = max(m,p);

    }
    ans -= m/2;
    
    
    //cout << ans <<endl;
    cout << ans <<endl;
    
    return 0;
}
