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

    string s;
    cin >>s;
    int l=s.length();
    stack<char> st;

    for (int i = 0; i < l; i++){
        if(st.empty() && s[i]=='T'){
            ans++;
        }else if(s[i]=='T'){ 
            st.pop();
        }else if(s[i] == 'S'){
            st.push(s[i]);
        }

    }

    ans += st.size();

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
