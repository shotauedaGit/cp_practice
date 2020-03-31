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
    bool flag=true;
    ll ans=0;

    int n;
    cin >>n;
    ll sum[n];
    map<ll,int> m;

    cin  >> sum[0];
    m[sum[0]]++;

    for (int i = 1; i < n; i++){
        int a;
        cin >> a;
        sum[i] = sum[i-1] + a;
        m[sum[i]]++;
    }
    

    for(pii s : m){
        ll x = s.second;
        ll add=0;
        if(s.first == 0)add = x*(x+1)/2;
        else add = x*(x-1)/2;
        ans += add;

        //cout <<s.first<<"::"<<x <<"-> "<<add<<endl;
    }


    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
