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

    int h,w,k;
    vector<string> s(h);
    vector<pair<int,pii>> b;
    vector<vector<int>> ans(h,vector<int>(w));

    for (int i = 0; i < h; i++)cin >>s[i];

    int st=0,ed=0;
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            if(s[i][j] == '#'){
                ed=j;
                b.eb(j,pii(st,ed));
                st = ed;
            }
        }
    }
    b.back().se.se = h-1;


    int p=0,cnt=1;
    while (1){
        for (int j = 0; j < w; j++){
            int now = b[p].fi;
            
            for(int i = b[p].se.fi; i <= b[p].se.se; i++){
                
            }
            
        }
        

        ++p;
        if(p+1 == b.size())break;
    }
    


    

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
