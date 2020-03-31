#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int bit=0,i=0;
    int num;
    int n[4];
    cin >>num;
    int bs,cs,ds;
    string ans="+++";

    while (i<4){
        n[i++]=num%10;
        num /= 10;
    }
    

    for (bit = 0; bit < 2<<3; bit++){
        bs=n[2];cs=n[1];ds=n[0];

        if(bit%2==0){
            ds *= -1;
            ans[0]='-';
            }else{
            ans[0]='+';
        }

        if((bit>>1)%2==0){
            cs *= -1;
            ans[1]='-';
            }else{
            ans[1]='+';
        }

        if((bit>>2)%2==0){
            bs *= -1;
            ans[2]='-';
            }else{
            ans[2]='+';
        }
        if(n[3]+bs+cs+ds==7)break;
    }
    


    //cout <<fixed<<setprecision(16)<< << endl;
    cout <<n[3]<<ans[2]<<n[2]<<ans[1]<<n[1]<<ans[0]<<n[0]<<"=7"<<endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
