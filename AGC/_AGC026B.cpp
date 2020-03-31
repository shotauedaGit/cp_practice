#include <bits/stdc++.h>
using namespace std;
    

int main(){
    bool flag=true;
    int t;
    long long a,b,c,d,p,q;
    cin >>t;


    for (int i = 0; i < t; i++){
        flag = true;
        cin >>a>>b>>c>>d;
        p = a%b;
        q = d%b;

        if(q==0){
            if(a<b)flag=false;
        }else{
            if(a < b  || b >= (((c+q-1)/q)-p))flag = false;
        }

        if(flag)cout << "Yes" <<endl;
        else cout << "No" <<endl;
    }



    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
