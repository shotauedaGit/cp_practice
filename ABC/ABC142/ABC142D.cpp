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

ll GCD(ll m,ll n){
    ll big,small;
    ll p=-1;
    big=max(m,n);
    small=min(m,n);

    while(1){
        p=big%small;
        if(p==0)break;
        big=small;
        small=p;
    }
    
    return small;
}

int main(){

    bool flag=true;

    ll ans=1,sum=0;
    
    ll a,b;
    cin >>a>>b;


    __int128_t ab = a*b;
    ll lcm = GCD(a,b);

    for(int i = 2; i <= sqrt(lcm) + 1; i++){
        
        if(lcm%i == 0){
            //ll temp = lcm;
            while (lcm%i == 0)lcm /= i;
            ++ans;

            //while (lcm%(temp/i) == 0)lcm /= temp/i;
            //++ans;
        }

        if(lcm <= 1)break;
    }

    if(lcm > 1)++ans;

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
