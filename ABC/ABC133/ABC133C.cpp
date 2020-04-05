#include <bits/stdc++.h>
using namespace std;



int main(){
    int ans=2020;
    int64_t l,r;
    cin >> l>>r;

    if((l/2019)==(r/2019)){
        for(int i = l%2019; i <= r%2019; i++){
            for(int j = l%2019; j <= i; j++){
                if(i==j)continue;
                ans=min(ans,(i*j)%2019);
            }
        }
    }else{
        ans=0;
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
