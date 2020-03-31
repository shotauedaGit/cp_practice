#include <bits/stdc++.h>
using namespace std;

#define INF ((1<<31)-1)  //int32_t
#define MOD 1000000007
#define MOD2  

#define all(a)  (a).begin(),(a).end()

#define mkp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;



int main(){
    bool flag=true;
    string s,subs;
    cin >>s;

    int i=0;
    while (i < s.length()){
        subs = s.substr(i,5);

        if(subs == "dream"){
        
            i += 5;
            subs = s.substr(i,2);

            if(subs == "er"){
                subs = s.substr(i,5);
                if(subs != "erase")i+=2;
            }

        }else if(subs == "erase"){
        
            i += 5;
            subs = s.substr(i,1);
            if(subs == "r")++i;
        
        }else{
            flag=false;
            break;
        }
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    if(flag)cout << "YES" <<endl;
    else cout << "NO" <<endl;
    
    return 0;
}
