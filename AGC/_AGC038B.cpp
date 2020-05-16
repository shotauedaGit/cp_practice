#include <bits/stdc++.h>
using namespace std;


#define INF 2147483647
#define LINF 9223372036854775807
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

typedef pair<int,int> P;
typedef pair<int,P> iP;
typedef pair<P,P> PP;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    bool flag=false;
    ll ans=0,sum=0;
    int n,k;
    cin>>n>>k;

    ans = n-k+1;
    vector<int> a(n),inc(n,1);
    list<int> seg;

    rep(i,n)cin>>a[i];

    int cnt=1;
    rep1(i,1,n){
        if(a[i-1]<a[i])++cnt;
        else cnt =1;
        inc[i]=cnt;
    }

    for(int ai:inc)cout<<ai<<" ";
    ln;

    rep(i,k){
        auto it = lower_bound(all(seg),a[i]);
        seg.insert(it,a[i]);
    }

    //db2(seg.front() , seg.back());
    bool fir=false;
    rep1(i,k,n){
        int del = a[max(0,i-k)];
        int nx = a[i];

        if(seg.front() == del && seg.back() < nx ){
            db2(seg.back() , nx);
            cout<<i<<"i,i+1 equ"<<endl;

            --ans;
        }else if(inc[i] >= k){
            cout<<i<<"sorted"<<endl;

            if(!fir){fir=true;continue;}
            --ans;
        }

        if(i >= k){
            auto er = upper_bound(all(seg),del);
            seg.erase(er);
        }
        auto it = lower_bound(all(seg),nx);
        seg.insert(it,nx);
    }

    cout<<ans<<endl;
    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    return 0;
}
