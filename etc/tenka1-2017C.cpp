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
    ll N;
    cin >>N;

    ll n,h,w;

    for (ll i = 1; i <= 3500; i++)
    {
        for (ll j = 1; j <= 3500; j++)
        {
            ll p=i+j;
            ll q=i*j;

            if((4*q-N*p > 0) &&  N*q % (4*q-N*p) == 0){
                
                n = N*q/(4*q-N*p);
                h=i;
                w=j;
                
                cout <<h<<" " <<n<<" "<<w<<'\n';
                return 0;
            }
        }
        
    }
    




    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
