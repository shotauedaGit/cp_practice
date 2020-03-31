#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=1;
    int n,m,x;
    int a;
    int costleft=0,costright=0;
    int ans=0;

    cin >>n>>m>>x;

    for (int i = 0; i < m; i++){
        cin >>a;
        if(x>a)costleft++;
        else costright++;
    }
    
    ans = min(costright,costleft);
    cout << ans <<endl;
    //cout <<fixed<<setprecision(16)<< ans <<endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
