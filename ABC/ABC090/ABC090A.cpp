#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int n = 0;
    char ch[9];
    for (int i = 0; i < 9; i++){
        cin >> ch[i];
    }

    for (int i = 0; i < 3; i++){
        cout << ch[4*i];
    }
    puts("\n");
    
    int flag=0;
    int ans=0;

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
