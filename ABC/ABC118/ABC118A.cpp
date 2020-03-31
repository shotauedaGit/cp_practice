#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int A,B;
    int ans=0;

    cin >> A>>B;
    if(B%A==0){
        cout << A+B <<endl;
    }else{
        cout << B-A <<endl;
    }
    return 0;
}
