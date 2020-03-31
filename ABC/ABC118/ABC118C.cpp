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
    int ans=0,MIN=1e9+1;
    int n;
    cin >> n;
    int data[n];

    cin >> data[0];
    for (int i = 1; i < n; i++){
        cin >>data[i];
        MIN = min(MIN,GCD(data[i-1],data[i]));
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << MIN << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
