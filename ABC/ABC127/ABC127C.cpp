#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int N,M;
    int L,R;
    int lmin=0,lmax=100000;
    int ans=0;
    cin >> N>>M;
    for(int i = 0;i < M;i++){
        cin >>L>>R;
        if(lmin<L)lmin=L;
        if(R<lmax)lmax=R;
    }
    ans=lmax-lmin+1;
    if(lmax<lmin)ans=0;
    cout << ans <<endl;
    return 0;
}
