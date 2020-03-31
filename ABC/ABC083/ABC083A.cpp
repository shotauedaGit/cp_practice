#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=0;
    int ans=0;
    int a,b,c,d;
    cin >> a>>b>>c>>d;

    if(a+b==c+d){
        cout << "Balanced"<<endl;
    }else if(a+b > c+d){
        cout << "Left"<<endl;
    }else{
        cout << "Right"<<endl;

    }

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
