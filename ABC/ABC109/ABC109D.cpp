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

    int h,w;
    cin >>h>>w;
    vector<vector<int>> g(h,vector<int>(w));
    vector<vector<int>> ansv;

    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            cin >>g[i][j];
        }
    }

    for (int i = 0; i < h-1; i++){
        for (int j = 0; j < w; j++){
            if(g[i][j]%2==1){
                --g[i][j];
                ++g[i+1][j];

                vector<int> eans(4);
                eans[0]=i+1;
                eans[1]=j+1;
                eans[2]=i+2;
                eans[3]=j+1;

                ansv.emplace_back(eans);
                ++ans;

            }
        }
    }

    for (int j = 0; j < w-1; j++){
        if(g[h-1][j]%2==1){
                --g[h-1][j];
                ++g[h-1][j+1];
                
                vector<int> eans(4);
                eans[0]=h;
                eans[1]=j+1;
                eans[2]=h;
                eans[3]=j+2;

                ansv.emplace_back(eans);
                ++ans;

        }
    }
    
    
    

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    for(auto v:ansv){
        cout << v[0] <<" " <<v[1] <<" " <<v[2] <<" " <<v[3] <<endl;
    }

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
