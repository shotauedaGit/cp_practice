#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0;
    int n;
    int64_t r1,ri,rinext;
    cin >> n;
    int64_t data[n];
    int64_t r[n];

    for (int i = 0; i < n; i++){
        cin >>data[i];
    }

    r1=2*data[0];
    for (int i = 1; i < n/2 + 1; i++){
        r1 += 2*(data[i*2]-data[i*2-1]);
    }
    r[0] = r1/2;

    for (int i = 1; i < n; i++){
        r[i] =2*data[i-1]-r[i-1];
    }
    
    for (int i = 0; i < n; i++)std::cout << r[i]<<" ";
    //cout <<fixed<<setprecision(16)<< << endl;
    cout << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
