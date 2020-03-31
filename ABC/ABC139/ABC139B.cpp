#include <bits/stdc++.h>
using namespace std;
    

int main(){
    bool flag=true;
    long long ans=0,tap=1;
    int a,b;
    cin >>a>>b;


    while (tap < b){
        ans++;
        tap--;
        tap += a;
    }
    


    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
