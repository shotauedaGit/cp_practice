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

string maxstrAsint(string a,string b){

    if(a.size() == b.size()){
        
        if(a >= b)return a;
        else return b;
    
    }else{
        if(a.size() > b.size())return a;
        else return b;
    }
}

int main(){

    bool flag=false;

    ll ans=0,sum=0;

    int n,m;
    cin >>n>>m;

    vector<int> mch = {INF,2,5,5,4,5,6,3,7,6};
    vector<int> canmake(m);

    vector<string> dp(n+1,"");


    for (int i = 0; i < m; i++){
        cin >> canmake[i];
    }

    for (int i = 0; i <= n; i++){
        for (int j = 0; j < m; j++){

            if(i >= mch[canmake[j]]){

                if(i == mch[canmake[j]] || dp[i-mch[canmake[j]]]!=""){
                    string app = to_string(canmake[j]);
                    dp[i] = maxstrAsint(dp[i],dp[i-mch[canmake[j]]]+app);
                }
            }

        }
        //cout << dp[i] << endl;
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << dp[n] << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
