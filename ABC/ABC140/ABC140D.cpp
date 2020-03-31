#include <bits/stdc++.h>
using namespace std;

#define all(a)  (a).begin(),(a).end()

#define mkp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;



int main(){
    bool flag=true;
    int sad=0,sad2=0;
    ll ans=0,sum=0;
    int n,k;
    string s;
    cin >>n>>k>>s;

    if(s[0]=='L')sad2++;
    for (int i = 0; i < n-1; i++){
        if(s[i]=='R' && s[i+1]=='L'){
            sad+=2;
            i++;
        }
    }
    if(s[n-1]=='R')sad2++;

    if(sad/2 >= k){
        ans = n - sad -sad2 + 2*k;
    }else {
        ans = n - 1;
    }



    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
