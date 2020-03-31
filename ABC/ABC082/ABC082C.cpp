#include <bits/stdc++.h>
using namespace std;
    

int main(){
    map<int,int> m1;
    int ans=0;
    int n,a;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >>a;
        if(m1.find(a) != m1.end())m1[a]++;
        else m1[a]=1;
    }

    for (auto p = m1.begin(); p != m1.end(); p++){
        if(p->first > p->second)ans+= p->second;
        else ans += (p->second)-(p->first);
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
