#include <bits/stdc++.h>
using namespace std;

#define all(a)  (a).begin(),(a).end()

#define mkp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;



int main(){
    bool flag=true;
    ll ans=0,sum=0;
    int n,count=0,mx=0;
    cin >>n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        while (a%2 == 0)
        {
            a/=2;
            ans++;
        }
    }
    



    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
