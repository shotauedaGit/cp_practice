#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0,sum=0;
    int n,a;
    int max1=0,max2=0;
    cin >> n;
    int data[n];
    int sorted[n];

    for (int i = 0; i < n; i++){
        cin >>data[i];
        sorted[i]=data[i];
    }
    
    sort(sorted,sorted+n,greater<int>());
    max1=sorted[0];
    int p=0;
    while (sorted[p] == sorted[0])p++;

    if(p>=n){
        max2=max1;
    }else if(p==1){
        max2=sorted[p];
    }else{
        max2=max1;
    }

    for (int i = 0; i < n; i++){
        if(data[i]==max1){
            std::cout << max2 << endl;
        }else{
            std::cout << max1 << endl;

        }
    }
    


    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
