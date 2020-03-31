#include <bits/stdc++.h>

using namespace std;

#define INF ((1<<30)-1)  //int32_t
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

    ll ans=INF,change=0;
    
    int n;
    string s;
    cin >>n>>s;

    for (int i = 1; i < n; i++){
        if(s[i] == 'E')change++;
    }

    ans = change;
    //cout <<change << " ";

    for (int i = 1; i < n; i++){
        if(s[i-1] == 'W')change++;
        if(s[i] == 'E')change--;
        //cout <<change << " ";
        ans = min(change,ans);
    }
    //puts("");

    //cout <<fixed<<setprecision(16)<< << endl;
    cout <<ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}