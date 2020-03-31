#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int a,b,k;
    int n=0,i;
    int ans;

    cin >>a>>b>>k;
    i=min(a,b);
    while (i > 0){
        if(a%i==0 && b%i==0)n++;
        if(n==k){
            ans=i;
            break;
        }
        i--;
    }
    

    cout << ans <<endl;
    return 0;
}
