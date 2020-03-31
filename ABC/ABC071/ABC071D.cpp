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
    int state,pstate;
    int n,st=1;

    string s1,s2;
    cin >>n;
    cin >>s1>>s2;

    if(s1[0] == s2[0]){
        ans = 3;
        pstate = 1;
    } else {
        ans = 6;
        pstate = -1;
        st++;
    }

    
    
    for (int i = st; i < n; i++){
        
        if(s1[i] == s2[i]){
            state = 1;
            if(pstate != -1)ans=(ans * 2)%MOD;
        }else{
            state = -1;
            if(pstate == -1)ans=(ans * 3)%MOD;
            else ans = (ans * 2)%MOD;
            ++i;
        }

        if(i == n-1)break;

        pstate = state;
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
