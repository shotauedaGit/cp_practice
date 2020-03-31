#include <bits/stdc++.h>
using namespace std;
    

int main(){
    long long s;
    long long w=1e9;

    cin >> s;

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << 0 << " "<< 0 << " ";
    cout << w << " "<< 1 << " ";
    if(s%w!=0)cout << (int)(w-(s%w)) << " "<< (int)((s/w)+1) << endl;
    else cout << 0 << " "<< (int)(s/w) << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
