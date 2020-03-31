#include <bits/stdc++.h>

using namespace std;

#define INF 1001001001
#define LINF 1001001001001001001
#define MOD 1000000007
#define MOD2 998244353

#define all(a)  (a).begin(),(a).end()

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

    string s;
    cin >>s;

    map<string,int> m;
    m["SAT"]=1;
    m["FRI"]=2;
    m["THU"]=3;
    m["WED"]=4;
    m["TUE"]=5;
    m["MON"]=6;
    m["SUN"]=7;


    //cout <<fixed<<setprecision(16)<< << endl;
    cout << m[s] << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
