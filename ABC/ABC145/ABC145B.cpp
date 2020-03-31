#include <bits/stdc++.h>

using namespace std;

#define INF 1001001001  //int32_t
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

    int n;
    string s;
    cin >>n>>s;

    if(n%2 == 1){
        flag = false;
    }else{
        for (int i = 0; i < n/2; i++)
        {
            if(s[i] != s[i + (n/2)]){
                flag = false;
                break;
            }
        }
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    if(flag)cout << "Yes" <<endl;
    else cout << "No" <<endl;
    
    return 0;
}
