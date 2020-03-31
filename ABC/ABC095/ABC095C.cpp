#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=0;
    int a,b,c,x,y;
    cin >>a>>b>>c>>x>>y;
    int ans=0;

    if(x>y){

        if(2*c < a + b)ans += 2*c*y;
        else ans += (a+b)*y;

        if(2*c < a)ans += 2*c*(x-y);
        else ans += a*(x-y);
    
    }else{

        if(2*c < a + b)ans += 2*c*x;
        else ans += (a+b)*x;

        if(2*c < b)ans += 2*c*(y-x);
        else ans += b*(y-x);

    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
