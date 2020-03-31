#include <bits/stdc++.h>
using namespace std;
#define INF (1<<31)-1

int main(){
    int ans=0,sum=0;
    int n,k;
    
    cin >>n>>k;
    int h[n];
    int cost[n];


    for (int i = 0; i < n; i++){
        cin >> h[i];
    }

    cost[0]=0;

    for (int i = 1; i < n; i++){
        int c=INF;

        for (int j = 1; j <= min(k,i); j++){
            c=min(c,cost[i-j]+abs(h[i]-h[i-j]));
        }
        cost[i] = c;
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << cost[n-1] << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
