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

    int h,w,a,b;
    cin >>h>>w>>a>>b;

    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= w; j++){
            
            if(j <= a){
                if(i <= b){
                    cout << 1;
                }else{
                    cout << 0;
                }
            }else{
                if(i <= b){
                    cout << 0;
                }else{
                    cout << 1;
                }
            }
        }
        cout <<'\n';
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
