#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int r,d,x2000;
    int preans=0,ans=0;

    cin >> r >> d >> x2000;

    preans = x2000;
    for (int i=0; i<10; i++){
        ans = (r*preans)-d;

        cout << ans <<endl;

        preans = ans;
    }
    return 0;
}
