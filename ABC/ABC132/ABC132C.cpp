#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0;
    int n;
    cin >> n;

    int p=(n/2)-1,q=(n/2);

    int data[n];
    
    for (int i = 0; i < n; i++){
        cin >> data[i];
    }
    
    sort(data,data+n);

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << data[q]-data[p] << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
