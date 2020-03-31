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
    int n,m=100001;
    cin >>n;
    vector< pair<int,int> > b(n-1);
    vector<int> a(n);

    fill(all(a),-1);

    for (int i = 0; i < n-1; i++){
        int bi;
        cin >>bi;
        b[i] = mkp(bi,i);
    }

    sort(all(b));
    
    for (int i = 0; i < n-1; i++){
        int x=b[i].second;
        int v=b[i].first;

        if(a[x]==-1)a[x]=v;
        if(a[x+1]==-1)a[x+1]=v;
    }
    
    for (int i = 0; i < n; i++)ans += a[i];
    



    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
