#include <bits/stdc++.h>
using namespace std;

#define INF 1001001001
#define LINF 1001001001001001001
#define MOD 1000000007
#define MOD2 998244353

#define all(a)  (a).begin(),(a).end()
#define dig(n)  to_string(n).length()

#define pb push_back
#define eb emplace_back
#define mkp make_pair

#define se second
#define fi first

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,pii> ppii;

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int n,k,r,s,p;
    cin >>n>>k>>r>>s>>p;
    vector<int> loss(n,-1);

    string t;
    cin >> t;

    for (int i = 0; i < n; i++){

        if(i >= k && t[i-k] == t[i] && loss[i-k] == -1){
            loss[i]=1;
        }else{
            if(t[i]=='r'){
                ans += p;
            }else if(t[i]=='s'){
                ans += r;
            }else{
                ans += s;
            }
        }
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
