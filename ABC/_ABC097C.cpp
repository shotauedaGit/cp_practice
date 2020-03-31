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

    string s;
    int k;
    cin >>s>>k;
    vector<string> topk;

    topk.emplace_back(s[0]);
    for (int i = 1; i < min(k,(int)s.length()); i++){
        topk.emplace_back(topk[i-1] + s[i]);
    }
    
    string nw;
    for (int i = 1; i < s.length(); i++){
        nw = to_string(s[i]);
        for (int j = i+1; j < min(i+k,(int)s.length()); j++){
            
            if(nw < topk[topk.size()-1]){

                topk.insert(lower_bound(all(topk),nw),nw);
                topk.pop_back();

            }

            nw = (nw + s[j]) ;
        }
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << topk[k-1] << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
