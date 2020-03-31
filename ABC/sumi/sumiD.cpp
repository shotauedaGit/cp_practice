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

    int n;
    string s;
    cin >>n>>s;

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            for (int k = 0; k < 10; k++){
                
                bool ok=false;
                int d=1;

                for (int p = 0; p < n; p++){

                    switch (d){
                    case 1:
                        if(s[p]=='0'+i)++d;
                        break;
                    case 2:
                        if(s[p]=='0'+j)++d;
                        break;
                    case 3:
                        if(s[p]=='0'+k)ok=true;
                        break;

                    default:
                        break;
                    }
                }

                if(ok)++ans;
            }
        }
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
