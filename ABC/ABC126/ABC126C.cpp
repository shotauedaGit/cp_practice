#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int N,K,p,i;
    double ans=0;
    cin >>N>>K;

    for (i = 1; i <= N; i++){
        p=0;
        while (i*pow(2.0,p)<K){
            p++;
        }
        ans += (pow(2.0,-p))/N;
    }

    cout <<fixed<<setprecision(16)<< ans <<endl;
    return 0;
}
