#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=0;

    int ans=0;
    int x,y;
    int xi,yi;
    int n,m;
    int maxX=-101,minY=101;
    cin >> n >> m;
    cin >>x>>y;

    for (int i = 0; i < n; i++){
        cin >>xi;
        maxX=max(maxX,xi);
    }
    for (int i = 0; i < m; i++){
        cin >>yi;
        minY=min(minY,yi);
    }
    
    if(x<y && maxX <minY && !(y<=maxX) && !(minY<=x)){
        flag=0;
    }else{
        flag=1;
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    if(flag==1)cout << "War" <<endl;
    else cout << "No War" <<endl;
    
    return 0;
}
