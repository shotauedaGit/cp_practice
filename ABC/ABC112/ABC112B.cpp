#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int MIN=1001;
    int c,t;
    int N,T;
    cin >>N>>T;
    for (int i = 0; i < N; i++){
        cin >>c>>t;
        if(t<=T){
            MIN=min(MIN,c);
        }
    }
    //cout << ans <<endl;
    if(MIN==1001){cout << "TLE" << std::endl;}else{cout << MIN <<endl;}
    
    return 0;
}
