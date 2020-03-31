#include <bits/stdc++.h>
using namespace std;
    

int main(){
    string s;
    int n,k;

    cin >> n>>k>>s;
    if(s[k]=='A')s[k]='a';
    if(s[k]=='B')s[k]='b';
    if(s[k]=='C')s[k]='c';

    cout << s <<endl;
    return 0;
}
