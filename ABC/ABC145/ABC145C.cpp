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

    int n;
    vector<pii> tpos;
    double dist[8][8];

long double solve(vector<bool> v,int nv,long double td){
    long double ret = 0;

    int visted = 0;
    for (int i = 0; i < v.size(); i++){
        if(i == nv)continue;
        if(v[i] == true){
            ++visted;
            continue;
        }

        v[i] = true;
        ret += dist[i][nv] + solve(v,i,td);
    }
    
    if(visted == v.size()-1){
        return 0;
    }

    return ret;
}

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    cin >>n;
    tpos.resize(n);

    for (int i = 0; i < n; i++){
        int x,y;
        cin >>x>>y;
        tpos[i] = make_pair(x,y);
    }
    
    long double td = 0;
    long double nfact = 1,nfact2=1;

    for (int i = 1; i <= n-2; i++)nfact2 *= i;
    for (int i = 1; i <= n; i++)nfact *= i;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(i==j)continue;

            double x = abs(tpos[i].first - tpos[j].first);
            double y = abs(tpos[i].second - tpos[j].second);

            double sqd = x*x + y*y;

            dist[i][j] = sqrt(sqd);
            dist[j][i] = sqrt(sqd);


            td += sqrt(sqd)*nfact2;
        }
    }

    /*

    for (int i = 0; i < n; i++){
        vector<bool> v(n,false);
        v[i]=true;
        td += solve(v,i,0);
    }
    */

    cout <<fixed<<setprecision(16)<< (n-1)*td/nfact << endl;
    //cout << td/nfact << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
