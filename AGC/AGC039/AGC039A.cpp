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

    bool flag=true;

    ll ans=0,sum=0;
    
    string s;
    ll k;
    cin >>s>>k;
    ll n = s.length();

    vector<int> len(n,0);

    int i=0,cnt=0,st=0;
    int last=0;

    while (i < n){
        bool f=false;
        cnt = 1;
        st = i;

        while (s[(i+1)%n] == s[i] && i < n)
        {
            ++cnt;

            if(i==n-1){
                len[st] = cnt + len[0] -1;
                if(st!=0)len[0] = 0;
                f=true;

                if(len[st] == n){
                    ans += (n*k)/2;
                    cout << ans << endl;
                    return 0;
                }

                if(len[st]%2==0)ans -= 1;

                break; 
            }
            
            ++i;
            
        }
        
        if(!f)len[st] = cnt;
        
        if(cnt>1)last=st;

        ++i;
    }

    //for(int a:len)cout << a << " ";
    //puts("\n");

    for (int i = 0; i < n; i++){
        ans += (len[i]/2)*k;
    }


    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
