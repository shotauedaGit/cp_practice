#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int n,a,b,ans=0,p,sum;

    cin >> n>>a>>b;
    for (int i = 1; i <= n; i++){
        p=i;
        sum=0;

        while (p>=1){
            sum += p%10;
            p-=(p%10);p/=10;
        }
        
        if(a<=sum && sum<=b)ans+=i;
    }
    

    cout << ans <<endl;
    return 0;
}
