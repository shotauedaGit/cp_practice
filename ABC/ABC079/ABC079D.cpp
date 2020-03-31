#include <bits/stdc++.h>

using namespace std;

#define INF 1001001001  //int32_t
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

    int h,w;
    cin >>h>>w;

    vector<vector<int>> minmp(10,vector<int>(10,INF));

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            int c;
            cin >>c;
            minmp[i][j] = c;
        }
    }

    for (int k = 0; k < 10; k++){
        //int ki=k/10,kj=k%10;

        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                //if(i==j)minmp[i][j]=0;

                minmp[i][j] = min(minmp[i][j],minmp[i][k] + minmp[k][j]);
            }
        }
    }
    
    /*
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            printf("%6d ",minmp[i][j]);
        }
        puts("");
    }
    */

    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            int a;
            cin >>a;
            if(a == -1)continue;

            ans += minmp[a][1];
        }
        
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
