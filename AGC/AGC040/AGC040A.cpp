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

void p(int i,int n){
    cout <<i<<"::"<<n<<endl;
}



int main(){

    string s;
    ll ANS=0;

    cin >>s;

    int n = s.length();
    vector<int> ans(n+1);

    int i = 0;
    while (i < n){
        int c=0;

        if(s[i] == '<'){

            while(s[i+c] == '<'){
                ans[i+c] = c;
                //p(i+c,c);

                c++;

                if(i+c > n)break;
            }
            ans[i+c]=c;
        }else{

            while(s[i+c] == '>'){
                c++;
                if(i+c > n)break;
            }

            ans[i] = max(ans[i],c);
            //cout <<i<< " is now:: "<<ans[i]<<endl;

            for (int k = i+1; k <= i+c; k++){
                ans[k] = c - (k - i);
                //p(k,c-(k-i));
            }
        }

        i = i+c;
    }
    
    for(int a:ans){
        //cout << a;
        ANS += a;
    }
    cout <<endl<< ANS << endl;

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
