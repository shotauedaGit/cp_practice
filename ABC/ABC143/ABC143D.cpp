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
    
    int n;
    cin >>n;

    vector<int> l(n),g(n),s(n);
    //vector<int> s;

    for (int i = 0; i < n; i++){
        cin >>l[i];
        g[i]=l[i];
        s[i]=l[i];
    }

    sort(all(s));
    sort(all(g),greater<int>());

    for (int i = 0; i < n-2; i++){
        for (int j = i+1; j < n-1; j++){
            int add=0;
            add =(n-j-1) - (upper_bound(all(s),g[i]-g[j]) - s.begin());
            
            if(add < 0)continue;

            ans += add;
            //cout << "g[j]:"<<g[j]<<" "<< add << " ";
        }
        //puts("\n");
    }

    /*for (int i = 0; i < n; i++){
        int add = s.end() - upper_bound(all(s),g[i]);
        ans += add;
    }*/
    

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
