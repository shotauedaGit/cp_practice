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


int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int n,p=0,q=0,r=0;
    cin >>n;

    for (int i = 0; i < n; i++){
        int ai;
        cin >>ai;

        if(ai%4 == 0){
            ++p;
        }else if(ai % 2 == 0){
            ++q;
        }else{
            ++r;
        }
    }
    
    if(r <= p)flag=true;
    else if(q == 0 && r == p+1)flag = true;

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    if(flag)cout << "Yes" <<endl;
    else cout << "No" <<endl;
    
    return 0;
}
