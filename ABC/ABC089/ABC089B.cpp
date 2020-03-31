#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0;
    int n;
    cin >> n;
    char ch;

    for (int i = 0; i < n; i++){
        cin >> ch;
        if(ch=='Y'){
            std::cout << "Four" << '\n';
            return  0;
        }
    }
    //cout <<fixed<<setprecision(16)<< << endl;
    cout << "Three" << endl;
    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
