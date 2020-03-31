#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=0;
    int a,b,c;
    cin >>a>>b>>c;
    int ans=0;
    int MAX,maxmod2;
    int amod2=a%2,bmod2=b%2,cmod2=c%2;

    MAX=max(max(a,b),c);
    maxmod2 = MAX%2;

    ans += (MAX-a)/2 + (MAX-b)/2 + (MAX-c)/2;

    flag = abs(maxmod2-amod2) + abs(maxmod2-bmod2) +abs(maxmod2-cmod2);

    if(flag == 2)ans++;
    else if(flag == 1)ans += 2;

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
