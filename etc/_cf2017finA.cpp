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

    vector<int>ins={0,3,4,5};
    string KIHBR = "KIHBR",tmp=KIHBR,A="A";
    map<string,int> isok;

    for (int i = 0; i < (1<<4); i++){
        tmp=KIHBR;
        for (int j = 0; j < 4; j++){
            if((1<<j)&i == j){
                bitset<4> bi,bj;
                bi=i;bj=j;
                cout <<bi<<" "<<bj<<endl;

                tmp.insert(ins[j],A);
            }
        }
        isok[tmp] = 1;
        cout<<tmp<<endl;
    }

    string s;
    cin >>s;

    if(isok[s]==1)flag=true;

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout <<  << endl;

    if(flag)cout << "YES" <<endl;
    else cout << "NO" <<endl;
    
    return 0;
}
