#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=0;
    int n,p;
    int64_t sum=0,k;
    int64_t ans=0;

    cin >>n>>k;
    int a[n];
    int index[n];

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        
        p=i;
        sum=0;
        while (sum < k){
            sum += a[p];
            p++;
        }
        index[i]=p-1;
        
    }

    for (int i = 0; i < n; i++){
        ans += n - index[i];
    }
    

    //cout <<fixed<<setprecision(16)<< <<endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
