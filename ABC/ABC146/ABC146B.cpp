#include <bits/stdc++.h>

using namespace std;

#define INF 1001001001
#define LINF 1001001001001001001
#define MOD 1000000007
#define MOD2 998244353

#define all(a)  (a).begin(),(a).end()

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

    for (int i = 0; i < s.size(); i++){
        int p = s[i] - 'A';

        char nc = 'A' + (p+n)%26;
        
        s[i] = nc;
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << s << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
