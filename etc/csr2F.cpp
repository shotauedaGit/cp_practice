#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0;
    int A,B,p,f;
    int N;
    cin >>N;
    int dataA[N];
    long int dataB[N];

    for (int i = 0; i < N; i++){
        cin >>A>>B;
        dataA[i]=A+B;
        dataB[i]=A*B;
        f=1;
        for (int j = i-1; j >= 0; j--){
            if((dataA[j]==A+B)&&(dataB[j]==A*B)){
                f=0;
                break;
            }
        }
        if(f==1)ans++;
    }
    cout <<ans<<endl;
    return 0;
}
