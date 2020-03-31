#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int64_t ans=0;
    int A,B,p;
    int N;
    cin >>N;
    for (int i = 0; i < N; i++){
        
        cin >> A>>B;

        if(A>=B*2){
            p=B;
        }else{
            p=A/2;
        }
        
        ans+=p;
        
    }
    cout <<ans<<endl;
    return 0;
}
