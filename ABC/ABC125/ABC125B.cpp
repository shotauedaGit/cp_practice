#include <iostream>
using namespace std;
    

int main(){
    int i,n,c[21],v[21];
    int vc=0;

    cin >> n;

    for (i = 0; i < n; i++){
        cin >> v[i];
    }
    for (i = 0; i < n; i++){
        cin >> c[i];
    }
    for (i = 0; i < n; i++){
        if(v[i]>c[i])vc+=v[i]-c[i];
    }
    cout << vc  <<endl;
    return 0;
}
