#include <bits/stdc++.h>
using namespace std;

#define INF ((1<<30)-1)  //int32_t
#define MOD 1000000007
#define MOD2  

#define all(a)  (a).begin(),(a).end()

#define mkp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll calc(ll n,ll x,bool is3,bool is5,bool is7){

    if(x > n)return 0;
    ll ret=0;
    if(is3&&is5&&is7)++ret;
    ret += calc(n,(10*x)+3,true,is5,is7);
    ret += calc(n,(10*x)+5,is3,true,is7);
    ret += calc(n,(10*x)+7,is3,is5,true);

    return ret;
}

int main(){
    bool flag=true;
    ll ans=0,sum=0;

    int n,m;
    cin >>n;


    //cout <<fixed<<setprecision(16)<< << endl;
    cout << calc(n,0,false,false,false) << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
