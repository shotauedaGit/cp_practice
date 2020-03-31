#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int n,a;
    set<int> s;
    int ans;

    cin >>n;
    for (int i = 0; i < n; i++){
        cin >> a;
        s.insert(a);
    }
    cout << s.size() <<endl;
    //cout <<fixed<<setprecision(10)<< ans <<endl;
    
    return 0;
}
