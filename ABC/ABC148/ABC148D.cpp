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

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int n;
    cin >>n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >>a[i];
    }

    int i=0;
    int t=1,br=0;
    while (i < n){
        while (a[i] != t && i < n){
            //cout <<a[i]<<endl;

            ++br;
            ++i;
        }
        //cout <<a[i] <<"  !!!"<<endl;

        ++t;
        ++i;
    }

    if(br == n)br=-1;
    
    

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << br << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
