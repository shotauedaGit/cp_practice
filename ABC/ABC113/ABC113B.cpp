#include <bits/stdc++.h>
using namespace std;
    

int main(){
    double N,T,A,MIN=999999999;
    double t;
    int H;
    int ans;

    cin >>N>>T>>A;
    for (int i = 0; i < N; i++){
        cin >> H;

        t=T-(double)(H*0.006);
        
        if(fabs(t-A)<MIN){
            MIN=fabs(t-A);
            ans=i+1;
        }
    
    }
    
    
    //cout << ans <<endl;
    cout << ans <<endl;
    
    return 0;
}
