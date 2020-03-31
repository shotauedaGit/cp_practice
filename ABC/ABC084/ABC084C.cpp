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
    ll ans=0,sum=0;

    int n;
    cin >>n;
    vector<int> c(n-1),s(n-1),f(n-1);

    for (int i = 0; i < n-1; i++){
        cin >>c[i]>>s[i]>>f[i];
    }
    
    for(int j = 0; j < n;++j){
        
        int t=0;
        for (int i = j; i < n-1; i++)
        {
            if(t/f[i] < s[i]/f[i])t = s[i] + c[i];
            else{
                t = f[i]*((t + f[i] - 1)/f[i]) + c[i]; 
            }
        }
        cout << t << endl;
    }

    //cout <<fixed<<setprecision(16)<< << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
