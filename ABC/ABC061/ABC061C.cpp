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

    bool flag=false;

    ll ans=0,sum=0;
    ll n,k;
    cin >>n>>k;

    map<int,ll> arr;

    for (int i = 0; i < n; i++)
    {
        int a,b;
        cin >>a>>b;
        arr[a] += b;
    }
    

    auto p=arr.begin();
    int curans;

    while (sum < k){
        sum += p->second;
        curans = p->first;
        ++p;

        cout << curans << endl;
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << curans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
