#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0;
    int N;
    cin >>N;
    for (int i = 0; i < N; i++){
        int A,B;
        cin >> A>>B;
        ans=max(ans,A+B);
        
    }
    cout <<ans<<endl;
    return 0;
}
