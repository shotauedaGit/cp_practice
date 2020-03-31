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

    map<int,int> x;

    for (int i = 1; i <= 60000; i++){
        int tax = (double)i*1.08;
        x[tax]=i;
    }

    if(x.find(n) == x.end()){
        
    }else{
        flag=true;
        ans =x[n];
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout <<  << endl;

    if(flag)cout << ans <<endl;
    else cout << ":(" <<endl;
    
    return 0;
}
