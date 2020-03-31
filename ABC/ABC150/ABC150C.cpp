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

    int n,m;
    cin >>n;
    vector<int> array;
    vector<int> p,q;

    rep(i,n)array.pb(i+1);
    rep(i,n){
        int pi;
        cin >>pi;
        p.pb(pi);
    }
    rep(i,n){
        int pi;
        cin >>pi;
        q.pb(pi);
    }

    if(p == q){
    puts("0");
    return 0;
    }

    int cnt=0,cnt1=0;
    do {
        cnt++;
        if(array == p || array == q){
            cnt1++;
            //db3(cnt,cnt1,ans);

            if(cnt1 == 2){
                ans = abs(ans - cnt);
                break;
            }
            ans = cnt;
        }
    } while(next_permutation(array.begin(), array.end()));

    //cout <<fixed<<setprecision(16)<< << endl;
    cout<<ans<<endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
