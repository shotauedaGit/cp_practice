#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0,sum=0;
    int n,m;
    char c;
    string s;
    cin >>s;
    map<char,int> data;

    for (int i = 0; i < s.length(); i++){
        data[s[i]]++;
    }

    for (int i = 0; i < 26; i++)
    {
        if(data[(char)('a'+i)]==0){
            cout << (char)('a'+i) << endl;
            return 0;
        }
    }
    
    
    


    //cout <<fixed<<setprecision(16)<< << endl;
    cout << "None" << endl;
    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
