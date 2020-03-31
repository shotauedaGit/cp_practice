#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int i,n;
    cin >>n;
    for (i = 111; i <= 999; i=i+111){
        if((i-n)>=0)break;
    }
    cout << i <<endl;
    
    return 0;
}
