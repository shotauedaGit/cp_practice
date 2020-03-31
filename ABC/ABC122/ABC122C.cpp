#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0,app=0;
    int n,q;
    int l,r;
    cin >> n >> q;
    int data[n];
    string s;
    cin >> s;

    for (int i = 0; i < n-1; i++){
        
        if(s[i]=='A' && s[i+1]=='C'){
            data[i]=app;
            data[i+1] = ++app;
        }else{
            data[i]=app;
            data[i+1]=app;
        }
    }

    for (int i = 0; i < q; i++){
        cin >>l>>r;
        --l;--r;

        cout << data[r]-data[l] << '\n';
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
