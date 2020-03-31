#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0,spe=0;
    int n,k,a,it=0;
    cin >>n>>k;
    int data[200001];

    for (int i = 0; i < n; i++){
        cin >>a;
        if(data[a]==0)spe++;
        data[a]++;
    }

    sort(data+1,data+n,greater<int>());
    for (int i = k+1; i <= spe; i++){
        if(k>=spe)break;
        ans += data[i];
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
