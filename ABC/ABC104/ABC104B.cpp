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

    bool flag=true;
    ll ans=0,sum=0;
    int i=0;
    string s;
    cin >>s;    

    if(s[0]!= 'A')flag=false;

    bool C=false;
    for (i = 1; flag && i < s.length(); i++){
    
        if(2 <= i && i < s.length()-1){
            if(C && s[i]=='C'){
                flag=false;
            }else if(s[i]=='C'){
                C=true;
            }else if('A'<= s[i] && s[i] <= 'Z'){
                flag=false;
            }

        }else{
            if('A'<= s[i] && s[i] <= 'Z'){
                flag=false;
            }
        }
    }

    if(!C)flag=false;

    if(flag)cout << "AC";
    else cout << "WA";
    
    return 0;
}
