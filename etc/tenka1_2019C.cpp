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
    ll ans=0,sum=0,mn=INF;

    int n;
    string s;
    cin >>n>>s;

    for (int i = 0; i < n; i++){

        mn = min(mn,ans);

        if(s[i] == '#'){
            ans += 1;
        }else{
            sum += 1;
            ans -= 1;
        }
    }
    mn = min(mn,ans);
    
    ans = mn + sum;

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
