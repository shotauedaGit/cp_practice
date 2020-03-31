#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int i,n,c[10]={};

    cin >> n;

	c[n%10]++;
    n-=n%10;n/10;
    c[n%10]++;
    n-=n%10;n/10;
    c[n%10]++;
    n-=n%10;n/10;
    c[n%10]++;
    for(i=0;i<10;i++){
        if(true/*c[i]>=3*/){
            cout << c[i] <<endl;
            //return 0;
        }
    }
    
    cout << "No" <<endl;
    return 0;
}