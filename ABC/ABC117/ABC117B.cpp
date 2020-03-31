#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int N,L,MAX=0,sum=0;
    cin >>N;
    for (int i = 0; i < N; i++){
        cin >> L;
        sum += L;
        MAX=max(MAX,L);

    }
    if(MAX < (sum-MAX))cout << "Yes" <<endl;
    else cout << "No" <<endl;
    
    //cout << ans <<endl;

    
    return 0;
}
