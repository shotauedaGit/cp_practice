#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=1;
    int a,b;
    int di[5];
    int n,p,j;
    int ans=0;

    cin >>a>>b;
    
    for (int i = a; i <= b; i++){
        j=0;
        p=i;

        while (p>0){
            di[j] = (p%10);
            p /= 10;
            j++;
        }

        flag=1;
        for (int k = 0; k < 5; k++){
            if(di[k] != di[4-k])flag=0;
        }

        if(flag==1)ans++;
    }

    
    cout << ans <<endl;
    //cout <<fixed<<setprecision(16)<< ans <<endl;
    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
