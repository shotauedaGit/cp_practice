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
    cin >>n;
    list<int> l;

    for (int i = 0; i < n; i++){
        int ai;
        cin>>ai;
        
        if(i % 2==0){
            l.push_back(ai);
        }else{
            l.push_front(ai);
        }
    }
    
    if(n%2==1)l.reverse();
    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    for(int li : l)cout << li << " ";

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
