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

    int n;
    cin >>n;

    vector<ll> a(n),cr;

    for (int i = 0; i < n; i++){
        cin >>a[i];
    }
    

    int i=0;
    while (1){
        ll crust = 0;
        while (a[i] != 0 && i < n){
            crust += a[i];
            ++i;
        }
        cr.emplace_back(crust);
        if(i >= n)break;
        ++i;
    }

    for(ll c:cr){
        ans += c/2;
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}


/*
1 #
2 #
3 #
4 #
*/