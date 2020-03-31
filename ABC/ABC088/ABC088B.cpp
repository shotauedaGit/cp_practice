#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int n;
    int alice=0,bob=0;

    cin >>n;
    int data[n];
    for (int i = 0; i < n; i++){
        cin >> data[i];
    }

    sort(data,data+n,greater<int>());
    
    for (int i = 0; i < n; i++){
        if(i%2==0)alice+=data[i];
        else bob += data[i];
    }
    
    //cout << ans <<endl;
    cout << alice - bob <<endl;
    
    return 0;
}
