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

ll l(int d){
    ll ret=(1LL << d+2)-3LL;
    return ret;
}

ll p(int d){
    ll ret=(1LL << d+1)-1LL;
    return ret;
}

ll solve(ll rest,int d){

    if(d==0){
        //puts("1");
        return 1;
    }

    ll b1=l(d-1)+2;
    ll b2=2*l(d-1)+ 3;
    ll b3;

    if(rest==1){
        //puts("0");
        return 0;
    }else if(b1 > rest  && rest>1){
        return solve(rest-1,d-1);
    }else if(b1 == rest){
        //cout <<p(d-1)+1LL<<endl;
        return p(d-1)+1LL;
    }else if( b2 > rest  && rest > b1){
        //cout <<p(d-1)+1LL<<endl;
        return p(d-1)+1LL+solve(rest - b1,d-1);
    }else{
        //cout <<2*p(d-1)+1LL<<endl;
        return 2*p(d-1)+1LL;
    }
}

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    ll n,x;
    cin >>n>>x;
    //cout <<fixed<<setprecision(16)<< << endl;

    //for(int i = 0; i < n; i++)cout <<l(i)<< " " << p(i)<<endl;

    cout << solve(x,n) << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}


/*

ln = 
bn = 
pn = 


*/