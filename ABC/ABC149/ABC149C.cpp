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

    int x;
    cin >>x;

    if(x==2){
        cout << 2<< endl;
        return 0;
    }

    for (int i = x; true ; i++){
        
        bool f=true;
        for (int j = 2; j <= sqrt(x)+1; j++){
            if(i%j==0){
                f=false;
                break;
            }
        }

        if(f){
            ans = i;
            break;
        }
        
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
