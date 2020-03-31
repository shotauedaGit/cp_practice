#include <bits/stdc++.h>
using namespace std;
    
int GCD(int m,int n){
    int big,small;
    int p=-1;
    big=max(m,n);
    small=min(m,n);

    while(1){
        p=big%small;
        if(p==0)break;
        big=small;
        small=p;
    }
    
    return small;
}

int main(){
    int flag=0;
    int n;
    int a,b;

    cin >>n;

    for (int i = 0; i < n; i++){
        cin >>a>>b;
        cout << GCD(a,b) << endl;
    }

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
