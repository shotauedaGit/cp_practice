#include <iostream>
#include <string>
using namespace std;
    

int main(){
    int i,ans=0,max=0;
    string s;

    cin >> s;
    for(i=0;i<s.length();++i){
        if(s[i]=='A' ||s[i]=='G'||s[i]=='C'||s[i]=='T')ans++;
        else ans=0;

        if(ans>max)max=ans;
    }

    cout << max <<endl;
    return 0;
}
