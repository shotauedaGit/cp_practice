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
    vector<int>a;
    vector<int>dif;

    for (int i = 0; i < n; i++){
        int ai;
        cin>>ai;

        if(i!=0 && ai ==a.back())continue;
        a.eb(ai);

        int s=a.size();
        if(s>1){
            if(a[s-2] < a[s-1])dif.eb(1);
            else dif.eb(-1);
        }
    }

    /*

    bool skip=false;
    for (int i = 1; i < n-1; i++){
        if(!skip && dif[i-1]!=dif[i]){
            ++ans;
            skip=true;
            continue;
        }
        skip=false;
    }
    if(skip)++ans;

    */

    int i=0,l=a.size();
    while (i<l){
        ans++;

        if(i<l-1 && a[i]<a[i+1])while (a[i] < a[i+1] && i<n-1)i++;
        else while (a[i] > a[i+1] && i<n-1)i++;

        ++i;
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
