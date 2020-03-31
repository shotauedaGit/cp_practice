#include <iostream>
using namespace std;
    

int main(){
    int ans,sum,i,j;
    int a[21][21];
    int b[21];
    int c,m,n;

    cin >>n>>m>>c;

    for (i = 0; i < m; i++){
        cin >> b[i];
    }
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            cin >> a[i][j];
        }
        
    }
    
    

    for ( i = 0; i < n; i++){
        sum=0;
        for (size_t j = 0; j < m; j++){
            sum += a[i][j]*b[j];
        }
        sum += c;
        if(sum>0)ans++;
        
    }
    

    cout << ans <<endl;
    return 0;
}
