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
    ll ans=0,sum=0;

    int n,k;
    cin >>n>>k;
    int a[n],maxa=0;
    vector<ll> cds;

    for (int i = 0; i < n; i++){
        cin >>a[i];
        sum += a[i];
        maxa = max(maxa,a[i]);
    }
    
    for (ll i = 1; i*i <= sum; i++){
        if(sum % i == 0){
            cds.push_back(i);
            cds.push_back(sum/i);
        }
    }
    
    int mod[n]={};
    ll modsum,opr;
    
    for (int i = 0; i < cds.size(); ++i){
        modsum=0;

        for (int j = 0;j < n; ++j){
            mod[j]=a[j]%cds[i];
            modsum += mod[j];
        }
        sort(mod,mod+n,greater<int>());

        int p = modsum/cds[i];
        opr=0;
        for (int k = 0; k < p; ++k){
            opr += cds[i]-mod[k];
        }
        if(opr <= k)ans = max(ans,cds[i]);
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
