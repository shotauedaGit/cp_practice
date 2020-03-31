#include <bits/stdc++.h>
using namespace std;
int main(){
    int64_t N,ans;
    cin >>N;
    for (int i = 1; i <= (int)(sqrt(N+1)-1); i++)if((N-i) % i == 0)ans+=(N-i)/i;
    cout<<ans<<endl;
    return 0;
}
