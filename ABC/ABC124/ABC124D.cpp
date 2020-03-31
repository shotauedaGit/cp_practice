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

vector<int> ranlen(string s){

    char now = s[0];
    int i=0,count=0,len=s.size();
    vector<int>l;

    while(i < len){
        count=0;
        now = s[i];

        while(s[i]==now  && i < len){
        
            ++i;
            ++count;
        
        }

        l.push_back(count);
    }

    return l;
}

int main(){
    bool flag=true;
    ll ans=0,sum=0;

    int n,k;
    string s;
    cin >>n>>k>>s;

    vector<int> r = ranlen(s);
    r.insert(r.begin(),0);
    r.push_back(0);

    for (int i = 0; i < r.size(); i++){
        cout << r[i] << " ";
    }


    if(s[0] == 0){

        

    }else{



    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
