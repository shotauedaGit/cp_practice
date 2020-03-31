#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=1;
    int n,m;
    string s;
    map<string, int> m1;
    map<string, int>::iterator p;
    int ans=0;

    cin >>n;
    for (int i = 0; i < n; i++){
        cin >>s;
        p = m1.find(s);

        if(p != m1.end()){
            m1[s]++;
        }else{
            m1[s]=1;
        }

    }
    
    cin >>m;
    for (int i = 0; i < m; i++){
        cin >>s;
        p = m1.find(s);

        if(p != m1.end()){
            m1[s]--;
        }
    }

    for (p = m1.begin(); p !=m1.end(); i++){
        ans = max(ans,p->second);
    }
    
    cout << ans <<endl;
    //cout <<fixed<<setprecision(16)<< ans <<endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
