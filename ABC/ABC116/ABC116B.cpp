#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int p=0,s;
    int data[1000000];
    cin >>s;
    data[0]=s;
    while (1){
        p++;
        if(s%2==0){
            s=s/2;
        }else{
            s = 3*s + 1;
        }
        data[p]=s;

        for (int i = 0; i < p; i++){
            if(data[i]==s){
                cout << p+1 <<endl;
                return 0;
            }
        }
    }
}
