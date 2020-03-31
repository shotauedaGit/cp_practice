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

    bool flag=false;

    ll ans=0,sum=0;


    int n,m;
    cin >>n>>m;

    unordered_map<int,vector<pii>> city;
    vector<string> ids(m);
    string zero = "0";

    for (int i = 0; i < m; i++){
        int p,y;
        cin >>p>>y;
        city[p].emplace_back(y,i);
    }
    
    for(auto it:city){
        sort(it.second.begin(),it.second.end());

        //cout <<"pref "<<it.first<<"::";
        for (int i = 0; i < it.second.size(); i++){
            int y = it.second[i].first;
            int at = it.second[i].second;

            //cout <<"("<<y <<","<<at+1<<") ";

            string x = to_string(i+1);
            string pi = to_string(it.first);

            //cout << "city "<<at+1<<" is " <<i+1<<"th in pref:"<<it.first<< endl; 

            while(x.size() < 6)x = zero + x;
            while(pi.size() < 6)pi = zero + pi;

            
            ids[at] = pi+x;

        }
        //puts("");
    }



    /*for(auto it:city){
        for (int i = 0; i < it.second.size(); i++){

        }
    }*/

    for (int i = 0; i < m; i++){
        cout << ids[i] << endl;
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
