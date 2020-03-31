#include <iostream>
using namespace std;
    

int main(){
    int t[5],ft[5],p,i,max=0,ans=0;

    for ( i = 0; i < 5; i++){
        cin >> t[i];
        ft[i]=10*((t[i]+(10-1))/10);

        if((ft[i]-t[i])>max){
            max=ft[i]-t[i];
            p=i;
        }
    }
    for ( i = 0; i < 5; i++){
        if(i==p)continue;
        ans += ft[i];
    }
    ans += t[p];

    cout << ans << endl;
    return 0;
}
