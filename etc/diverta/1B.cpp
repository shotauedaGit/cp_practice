#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int r,g,b,a[3],n;
    int ans=0;
    int det=0;
    cin >>a[0]>>a[1]>>a[2]>>n;
    vector<int> vx(a,a+3);
    sort(vx.begin(),vx.end());

    for (int i = 0; i <= n/vx[2]; i++){
        for (int j = 0; j <= n/vx[1]; j++){
            det++;
            if((n-(i*vx[2]+j*vx[1])) % vx[0] == 0 && (n>=(i*vx[2]+j*vx[1])) )ans++;
        }
    }
    
    cout << det <<endl;
    return 0;
}
