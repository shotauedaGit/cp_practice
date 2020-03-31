#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=1;
    int cnt=0,nu[2],in[2];
    int ans=0,sum=0;
    int n,m;
    cin >> n;
    int data[n];

    for (int i = 0; i < n; i++){
        cin >>data[i];
        
        if(data[i]-1 != i){
            
            in[cnt]=i;
            nu[cnt]=data[i]-1;
            cnt++;
            
            if(cnt >= 2){
                flag=0;
                break;
            }
        }
    }
    
    if(cnt==0){
        flag=1;
    }else if(cnt==2){
        if(in[0] == nu[1] && in[1] == nu[0]){
            flag=1;
        }else{
            flag=0;
        }
    }else{
        flag=0;
    }



    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << (n-1)*(m-1) << endl;

    if(flag==1)cout << "YES" <<endl;
    else cout << "NO" <<endl;
    
    return 0;
}
