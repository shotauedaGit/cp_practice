#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=0;
    int n;
    cin >>n;
    int x[n],sorted[n];
    int small,big;
    int ans=0;

    for (int i = 0; i < n; i++){
        cin >> x[i];
        sorted[i] = x[i];
    }
    sort(sorted,sorted+n);
    
    small=sorted[(n-1)/2];
    big = sorted[((n-1)/2)+1];

    for (int i = 0; i < n; i++){
        
        if(x[i] <= small)cout << big << '\n';
        else if(x[i] >= big)cout << small << '\n';
    }

    //cout <<fixed<<setprecision(16)<< << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
