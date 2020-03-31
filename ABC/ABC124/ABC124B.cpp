#include <iostream>
using namespace std;
    

int main(){
    int i,j,flag=0,n,h[21];
    int ans=1;

    cin >> n;

    for (i = 0; i < n; i++){
        cin >> h[i];
    }

    for (i = 1; i < n; i++){

        for (j = i-1; j >= 0; j--){
            if(h[i]<h[j]){
                flag=0;
                break;
            }
            flag=1;
        }
        if (flag){
            ans++;
        }
        
    }
    
    cout << ans  <<endl;
    return 0;
}
