#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int n,y;
    int ans=0;
    int flag=0;

    cin >>n>>y;

    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            if(((n-(i+j))*1000 + 5000*j + 10000*i == y) && (n-(i+j)>=0)){
                flag=1;
                cout <<i<< " " <<j<< " " <<n-(i+j)<<endl;
                return 0;
            }
        }
    }

    if(flag==0)cout << "-1 -1 -1" <<endl;
    
    return 0;
}
