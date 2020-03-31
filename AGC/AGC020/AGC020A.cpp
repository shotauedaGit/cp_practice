#include <bits/stdc++.h>
using namespace std;

#define INF ((1<<31)-1)  //int32_t
#define MOD 1000000007
#define MOD2  

#define all(a)  (a).begin(),(a).end()

#define mkp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;



int main(){
    bool flag=true;
    ll ans=0,sum=0;
    int n,a,b;
    cin >>n>>a>>b;
    if((b-a)%2 == 0)flag=false;
    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    if(flag)cout << "Borys" <<endl;
    else cout << "Alice" <<endl;
    
    return 0;
}
