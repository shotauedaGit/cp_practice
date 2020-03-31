#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int p,q,r;
    int n;
    int ans=0;

    cin >>p>>q>>r;
    ans = p+q+r;
    ans -= max(p,max(q,r));
    
    cout << ans <<endl;
    //cout <<fixed<<setprecision(16)<< ans <<endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
