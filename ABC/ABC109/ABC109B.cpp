#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=1,ans=0;
    int n;
    cin >> n;
    string pastw,w;
    
    map<string, int> m;
    
    cin >> pastw;
    m[pastw]=1;
    for (int i = 1; i < n; i++){
        cin >> w;

        if(pastw[pastw.size()-1]!= w[0]){
            flag=0;
            break;
        }
        if(m.find(w)!=m.end()){
            flag=0;
            break;
        }else{
            m[w]=1;
        }

        pastw = w;
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    if(flag==1)cout << "Yes" <<endl;
    else cout << "No" <<endl;
    
    return 0;
}
