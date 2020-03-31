#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int A,B,ans=0;

    cin >> A >>B;

    if(A>=13){
        cout << B <<endl;
    }else if(A<=12 && 6<=A){
        cout << B/2 <<endl;
    }else{
        cout << 0 <<endl;
    }

    return 0;
}
