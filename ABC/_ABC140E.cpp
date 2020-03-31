#include <bits/stdc++.h>
using namespace std;
#define INF ((1<<31)-1)

#define all(a)  (a).begin(),(a).end()

#define mkp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;



int main(){
    bool flag=true;
    ll ans=0,sum=0;
    int n;
    cin >>n;
    vector<int> a(n+2),par(n+1);

    vector<pii> range(n+2),sot(n);

    a[0]=INF; a[n-1]= INF;
    
    range[0]=mkp(1,1);
    range[n+1]=mkp(n,n);

    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sot[i-1]=mkp(a[i],i);
        range[i]=mkp(i,i);
    }
    
    sort(all(sot));

    for (int i = 0; i < n; i++){
        int p=sot[i].second;

        if(a[p] > a[p-1]){
            range[p].first=range[p-1].first;
        }
        if(a[p] > a[p+1]){
            range[p].second=range[p+1].second;
        }


    }
    



    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
