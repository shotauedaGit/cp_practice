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
    ll ans=1,sum=0;
    
    ll n,p;
    cin >>n>>p;
    ll div=p;

    if(n == 1){
        std::cout << p << '\n';
        return 0;
    }

    for (int i = 2; i <= (int)sqrt(p); i++)
    {
        ll count=0;

        while (div % i==0)
        {
            div /= i;
            count++;
            
            if(count >= n){
                ans *= i;
                count = 0;
            }
        }
        if(div <= 1)break;
    }
    


    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
