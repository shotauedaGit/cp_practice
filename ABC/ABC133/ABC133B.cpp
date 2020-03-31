#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0;
    int n,d;
    int dist,distint;
    cin >> n>>d;
    int data[n][d];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < d; j++){
            cin >>data[i][j];
        }
    }


    for (int i = 0; i < n; i++){
        
        for (int j = 0; j < n; j++){
            if(j==i)continue;
            dist=0;
            for (int k = 0; k < d; k++){
                dist += (data[i][k]-data[j][k])*(data[i][k]-data[j][k]);
            }
            distint =(int)sqrt(dist);
            if(sqrt(dist)==distint)ans++;
        }
    }
    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans/2 << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
