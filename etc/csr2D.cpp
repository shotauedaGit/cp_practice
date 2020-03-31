#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int64_t ans=0;
    int A,B;
    int N;
    cin >>N;
    for (int i = 0; i < N; i++){
        
        cin >> A>>B;
        ans+=max(A,B);
        
    }
    cout <<ans<<endl;
    return 0;
}
