#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int n,a,min=9999,p;
    int ans=0;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >>a;
        p=0;
        while (a%2==0){
            a/=2;
            p++;
        }
        if(p<min)min=p;
    }

    cout << min <<endl;
    return 0;
}
