#include <bits/stdc++.h>
using namespace std;

#define INF 1001001001
#define LINF 1001001001001001001
#define LINF2 10010010010010
#define MOD 1000000007
#define MOD2 998244353

template<class T,class U>bool chmax(T &a, const U &b){if(a<b){a=b;return 1;}return 0;}
template<class T,class U>bool chmin(T &a, const U &b){if(b<a){a=b;return 1;}return 0;}

#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)
#define rep1(i,a,b) for(int a_=(a),b_=(b),i=a_;i<b_;++i)
#define repr(i,n) for(int _i=(n),i=_i;i>0;--i)

#define db(x) cerr<<#x<<" = "<<x<<" ";
#define db2(x,y) cerr<<"("<<#x<<", "<<#y<<") = ("<<x<<", "<<y<<") ";
#define db3(x,y,z) cerr<<"("<<#x<<", "<<#y<<", "<<#z<<") = ("<<x<<", "<<y<<", "<<z<<") ";
#define ln cout<<endl;

#define all(a)  (a).begin(),(a).end()
#define dig(n)  to_string(n).length()

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define se second
#define fi first

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,pii> ppii;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};



int main(){

    bool flag=false;
    ll ans=0,sum=0;

    string s;
    cin>>s;

    int n=s.length();

    vector<int> modP(n+1,0);

    
    int ten = 1;
    int modC = 0;

    rep(i,n){
        // cout<<s[n-1-i];ln;

        int add = (s[n-1-i] - '0');
        add = (add*ten)%2019;

        modC = (modC+add)%2019;
        modP[i+1] = modC;

        ten*=10;
        ten%=2019;
    }

    /*
    rep(i,n+1){
        string subs = s.substr(n-i,i+1);
        cout<<subs<<" % 2019 == "<<modP[i]<<endl;
    }
    */

    map<int,int>mfreq;

    for(int ai:modP)mfreq[ai]++;

    for(auto p:mfreq){
        //cout<<p.fi<<" "<<p.se<<endl;
        ll freq = p.se;

        ans += freq*(freq-1)/2;
    }

    cout<<ans<<endl;
    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
