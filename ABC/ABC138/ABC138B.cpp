#include <bits/stdc++.h>
using namespace std;
    

int main(){
    double ans=0;
    int n,m;
    
    cin >>n;
    
    for (int i = 0; i < n; i++){
        double a;
        cin >> a;

        ans += 1/a;
    }
    


    cout <<fixed<<setprecision(16)<< (double)(1/ans)  << endl;
    //cout << bunsi/bunbo << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
