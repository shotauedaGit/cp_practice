#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=0;
    int n;
    int ans=0;
    int c[9];
    int com1,com2,com3,row1,row2,row3;
    int b1to2,b2to3;
    int a1to2,a2to3;

    int a1,a2,a3,b1,b2,b3;


    for (int i = 0; i < 9; i++){
        cin >> c[i];
    }
    com1=c[0]+c[3]+c[6];
    com2=c[1]+c[4]+c[7];
    com3=c[2]+c[5]+c[8];

    row1=c[0]+c[1]+c[2];
    row2=c[3]+c[4]+c[5];
    row3=c[6]+c[7]+c[8];

    b1to2=(com1-com2)/3;
    b2to3=(com2-com3)/3;
    a1to2=(row1-row2)/3;
    a2to3=(row2-row3)/3;

    for (int i = 0; i <= 100; i++){
        for (int j = 0; j <= 100; j++){
            a1=i;
            b1=j;

            
            b2=b1-b1to2;
            b3=b2-b2to3;
            a2=a1-a1to2;
            a3=a2-a2to3;

            
        }
        
    }
    
    
    cout << ans <<endl;
    //cout <<fixed<<setprecision(16)<< ans <<endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
