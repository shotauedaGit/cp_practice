#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0,n,k,MIN=1000000001;
    cin >>n>>k;
    int data[n];
    for (int i = 0; i < n; i++){
        cin >> data[i];
    }
    sort(data,data+n,greater<int>());

    for (int i = 0; i <= n-k; i++){
        MIN =min(MIN,data[i]-data[k+i-1]);
    }
    
    cout << MIN <<endl;
    return 0;
}
