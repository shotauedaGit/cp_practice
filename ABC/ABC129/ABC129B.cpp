#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=1;
    int n;
    int summ=0;
    int m,MIN=1000000000;
    int ans=0;

    cin >>n;
    int w[n];
    
    
    for (int i = 0; i < n; i++){
        cin >> w[i];
        summ += w[i];
    }

    for (int i = 1; i < n; i++){
        m=0;
        for (int j = i; j < n; j++){
            m+=w[j];
        }

        MIN=min(MIN,abs((m)-(summ-m)));
    }
    
    
    
    cout << MIN <<endl;
    //cout <<fixed<<setprecision(16)<< ans <<endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
