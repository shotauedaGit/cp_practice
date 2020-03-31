#include <bits/stdc++.h>
using namespace std;
    

int main(){
    long long ans=0,sum=0;
    int n,m;
    cin >>n>>m;
    int x[m],d[m-1];

    cin >>x[0];
    int mn=x[0],mx=x[0];

    for (int i = 1; i < m; i++){
        cin >>x[i];
        mn = min(mn,x[i]);
        mx = max(mx,x[i]);
    }

    sort(x,x+m);

    for (int i = 1; i < m; i++){
        d[i-1] = abs(x[i]-x[i-1]);
    }

    sum = mx-mn;
    sort(d,d+m-1,greater<int>());


    if(n >= m){
        ans = 0;
    }else{
        for (int i = 0; i < n-1; i++){
            sum -= d[i]; 
        }
        ans = sum;
    }



    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
