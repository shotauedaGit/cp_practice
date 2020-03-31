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

bool isok(ll a,ll b,ll x,ll n){
    int dn=0;
    ll cp=n;

    while(cp>0){
        cp /= 10;
        ++dn;
    }

    //cout << n << " "<< dn ;

    if(a*n + b*dn <= x)return true;
    else return false;
}

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    ll a,b,x;

    cin >>a>>b>>x;

    ll bg=1,e=1e9;
    ll mid;

    while (bg <= e){
        
        mid = (bg+e)/2;
        if(!isok(a,b,x,mid)){
            //puts("\n");
            e = mid-1;
        }else{
            //puts("ok!");
            bg = mid+1;
        }
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout <<e<< endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
