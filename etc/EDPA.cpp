#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0,sum=0;
    int n,m;
    
    cin >>n;
    int h[n];
    int cost[n];


    for (int i = 0; i < n; i++){
        cin >> h[i];
    }

    cost[0]=0;
    cost[1]=abs(h[0]-h[1]);

    for (int i = 2; i < n; i++){
        int c;
        c=min(cost[i-1]+abs(h[i]-h[i-1]),cost[i-2]+abs(h[i]-h[i-2]));
        cost[i] = c;
    }
    
    


    //cout <<fixed<<setprecision(16)<< << endl;
    cout << cost[n-1] << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
