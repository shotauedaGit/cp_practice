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

    ll ans=0,ans1=0,ans2=0,sum=0;

    int n;
    cin >>n;
    vector<int> a(n),mx(n);

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(all(a),greater<int>());


    for(int j=0;j<2;++j){

        int add=2,p=0;
        bool isReturned=false;
        for (int i = 0; i < n; ++i){
            mx[p]=a[i];
            
            if(p == n-1 && !isReturned){

                mx[--p] = a[++i];
                add = -2;
                isReturned = true;

            }else if(p == n-2 && !isReturned){

                mx[++p] = a[++i];
                add = -2;
                isReturned = true;
            }

            p += add;
        }
        
        //for(int a:mx)cout << a << " ";
        //puts("");

        for (int i = 0; i < n-1; i++){
            if(j==0)ans1 += abs(mx[i] - mx[i+1]);
            else if(j==1) ans2 += abs(mx[i] - mx[i+1]);
        }

        sort(all(a));

    }


    ans = max(ans1,ans2);
    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
