#include <bits/stdc++.h>
using namespace std;

#define INF ((1<<31)-1)  //int32_t
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
    int x,y;
    cin >>x>>y;

    if(y >= x){
        ans = y-x;
        if(-x == y)ans = 1;
        else if(x < -y)ans = x+y+1;

    }else if(-x == y){
        ans = 1;
    }else if(x==0 || y==0){
        ans = abs(x-y)+1;
    }else if(x>0 && y<0){
        ans = -y -x + 1;
    }else{
        ans = x-y + 2;
    }

    


    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
