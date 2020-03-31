#include <iostream>
using namespace std;
    

int main(){

    int N,i,num[201];
    int ans=30,k;

    cin >> N;
    
    for (i = 0; i < N; i++){
        k=0;
        cin >> num[i];

        while(num[i]%2==0){
            num[i]/=2;
            k++;
        }
        if(k<ans)ans=k;
    }


    cout << ans << endl;
    return 0;
}