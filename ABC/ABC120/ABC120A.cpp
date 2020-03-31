#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int A,B,C;
    int ans=0;

    cin >> A >>B>>C;

    if(B/A>C)cout << C <<endl;
    else cout << B/A <<endl;
    return 0;
}
