#include <bits/stdc++.h>
using namespace std;
int main(){
    int ans=0;
    long long int x,y;
    cin >> x >> y;
    while ((x<<ans)<=y)ans++;
    cout << ans << endl;
    return 0;
}
