#include <bits/stdc++.h>
using namespace std;
    

int main(){
    string s;
    int ans;
    cin >> s;

    if((s[0]=='0' && !(s[1]=='0'))|| (s[0]=='1' &&(s[1]=='0' || s[1]=='1' || s[1]=='2'))){
        if(!((s[2]=='0' && !(s[3]=='0'))|| (s[2]=='1' &&(s[3]=='0' || s[3]=='1' || s[3]=='2')))){
            cout << "MMYY" <<endl;
            return 0;
        }
        cout << "AMBIGUOUS" <<endl;
        return 0;
    }

    if(!((s[0]=='0' && !(s[1]=='0'))|| (s[0]=='1' &&(s[1]=='0' || s[1]=='1' || s[1]=='2')))){
        if(((s[2]=='0' && !(s[3]=='0'))|| (s[2]=='1' &&(s[3]=='0' || s[3]=='1' || s[3]=='2')))){
            cout << "YYMM" <<endl;
            return 0;
        }
        cout << "NA" <<endl;
        return 0;
    }
}
