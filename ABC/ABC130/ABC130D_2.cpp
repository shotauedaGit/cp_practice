#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=0;
    int n,end=0,begin=0;
    int64_t sum=0,k;
    int64_t ans=0;
    cin >>n>>k;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    while (begin < n){
        while(sum < k && end<n){
            if(end < n)sum += a[end];
            end++;
        }
        if(sum >= k)ans += n-(end-1);
        sum -= a[begin];
        begin++;
    }
    //cout <<fixed<<setprecision(16)<< <<endl;
    cout << ans << endl;
    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
