#include <bits/stdc++.h>
using namespace std;
    

int main(){
    string s;
    int win=0;

    cin >>s;
    for (int i = 0; i < s.length(); i++){
        if(s[i]=='o')win++;
    }
    

    if (win + (15-s.length()) >= 8)
    {
        cout << "YES" <<endl;
    }
    else
    {
        cout << "NO" <<endl;
    }
    
    return 0;
}
