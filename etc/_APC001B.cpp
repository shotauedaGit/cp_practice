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

    ll ans=0,suma=0,sumb=0;
    int n;
    ll opr1=0,opr2=0;

    cin >>n;
    vector<int> a(n),b(n);

    for (int i = 0; i < n; i++){
        cin >> a[i];
        suma += a[i];
    }

    for (int i = 0; i < n; i++){
        cin >> b[i];
        sumb += b[i];
    }

    for (int i = 0; i < n; i++){
        if(b[i] < a[i]){
            opr1 += a[i] - b[i];
        }else{
            opr2 += ((b[i] - a[i])+1)/2;
        }
    }

    ll lim = suma - sumb;

    if(opr1 <= lim  && opr2 <= lim){
        flag = true;
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    if(flag)cout << "Yes" <<endl;
    else cout << "No" <<endl;
    
    return 0;
}
