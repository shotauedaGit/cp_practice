#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=0;
    int n,p=0;
    int64_t sum=0,k;
    int64_t ans=0;

    cin >>n>>k;
    int a[n];
    int sumfromtop[n];
    cin >> a[0];
    sumfromtop[0]=a[0];

    for (int i = 1; i < n; i++){
        cin >> a[i];
        sumfromtop[i]= sumfromtop[i-1] + a[i];
    }

    while (sumfromtop[p] < k)p++;
    ans += n-p;
    
    for (int i = 0; i < n-1; i++){
        
        p=i+1;
        while (sumfromtop[p]-sumfromtop[i] < k && (p<n))p++;
        ans += n-p;
    }
    

    //cout <<fixed<<setprecision(16)<< <<endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
