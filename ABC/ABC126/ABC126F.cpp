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

    int m,k;
    cin >>m>>k;

    if(k >= (1<<m)  || (m==1 && k==1)){
        cout << -1 <<endl;
        return 0;
    }else if(m == 0 && k == 0){
        cout << "0 0";
    }else if (m==1 && k==0){
        cout << "0 0 1 1";
    }else{

        for(int i = (1<<m)-1 ; i >= 0 ;--i){
            if(i!=k)cout << i << " ";
        }
        cout << k << " ";

        for(int i = 0; i < (1<<m) ;++i){
            if(i!=k)cout << i << " ";
        }
        cout << k << " ";
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
