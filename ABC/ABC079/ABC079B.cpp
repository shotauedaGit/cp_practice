#include <bits/stdc++.h>
using namespace std;
int main(){
    int i,n;
    int64_t lucas[87];
    lucas[0]=2;
    lucas[1]=1;
    cin >> n;
    for (i = 2; i <= n; i++){
        lucas[i]=lucas[i-1]+lucas[i-2];
    }
    

    cout << lucas[n] <<endl;
    return 0;
}
