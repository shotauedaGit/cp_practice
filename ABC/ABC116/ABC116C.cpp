#include <bits/stdc++.h>
using namespace std;
    
bool isBiggerthanN(int num,int n){
    if(num > n)return  true;
    else return  false;
}

int main(){
    int flag=1;
    int n,MAX=0;
    int ans=0;

    cin >>n;
    int h[n];
    for (int i = 0; i < n; i++){
        cin >>h[i];
        MAX=max(h[i],MAX);
    }

    for (int hei = 0; hei < MAX; hei++){
        int k=0;
        while (isBiggerthanN(h[k],hei)==false)k++;
        ans++;
        for (int i = k; i < n-1; i++){
            if((isBiggerthanN(h[i],hei)==false)&&(isBiggerthanN(h[i+1],hei)==true))ans++;
        }
    }
    cout << ans <<endl;
    //cout <<fixed<<setprecision(16)<< ans <<endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}


