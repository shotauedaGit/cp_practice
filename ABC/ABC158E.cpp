#include <bits/stdc++.h>
using namespace std;

#define INF 1001001001
#define LINF 1001001001001001001
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

    int n,p;
    string s;
    cin>>n>>p>>s;

    if(p==2){

        rep(i,n){
            int d = s[i]-'0';
            if(d%2==0)ans += (i+1);
        }

    }else if(p==5){

        rep(i,n){
            int d = s[i]-'0';
            if(d==5 || d==0)ans += (i+1);
        }

    }else{

        vector<int> mP(n,0);
        map<int,ll> mfq;

        mP[n-1] = ( (s[n-1]-'0') %p);
        mfq[ mP[n-1] ]++;
        mfq[0]++;

        int Md = 1;
        rep1(i,1,n){
            int pr = n-i;
            int pos = pr-1;
            Md = (Md*10)%p;

            mP[pos] = ( mP[pr]+(s[pos]-'0')*Md )%p;
            mfq[ mP[pos] ]++;
        }

        for(auto p:mfq){
            ll ap = p.second;
            ans += max(ap*(ap-1)/2,0LL);
        }

    }

    //cout <<fixed<<setprecision(16)<< << endl;
    
    cout<<ans<<endl;
    
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
