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
    string s;
    cin >>s;
    
    for (int i = 0; i < s.length(); i++)
    {
        if(i % 2 == 0){
            if(s[i] == 'L')flag = false;
        }else{
            if(s[i] == 'R')flag = false;
        }
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    if(flag)cout << "Yes" <<endl;
    else cout << "No" <<endl;
    
    return 0;
}
