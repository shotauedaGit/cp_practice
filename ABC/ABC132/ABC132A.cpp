#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=0;
    int a[4];
    int app=0;
    string s;
    cin >> s;

    map <char,int> m;

    for (int i = 0; i < 4; i++){
        m[s[i]] += 1;
    }
    if(m.size()==2 && m[s[0]]==2)flag=1;

    //cout <<fixed<<setprecision(16)<< << endl;

    if(flag==1)cout << "Yes" <<endl;
    else cout << "No" <<endl;
    
    return 0;
}
