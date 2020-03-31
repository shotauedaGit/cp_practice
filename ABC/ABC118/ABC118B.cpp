#include <bits/stdc++.h>
using namespace std;
    

int main(){
    
    int n,m,k,ans=0,aij;

    cin >>n>>m;
    
    int a[m]={};

    for (int i = 0; i < n; i++){
        cin >>k;
        for (int j = 0; j < k; j++){
            cin >>aij;
            a[--aij] += 1;
        }
    }

    for (int i = 0; i < m; i++){
        if(a[i]==n)ans++;
    }
    
    

    cout << ans <<endl;
    return 0;
}
