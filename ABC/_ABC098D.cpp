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

#define dbg(x) cerr<<#x<<" = "<<x<<" ";
#define dbg2(x,y) cerr<<"("<<#x<<", "<<#y<<") = ("<<x<<", "<<y<<") ";
#define dbg3(x,y,z) cerr<<"("<<#x<<", "<<#y<<", "<<#z<<") = ("<<x<<", "<<y<<", "<<z<<") ";
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

    int n;
    cin>>n;

    vector<int> a(n);
    rep(i,n)cin>>a[i];

    vector<int> Sxor(n+1,0);
    vector<int> Sai(n+1,0);
    vector<int> mxor(n,0);


    rep(i,n){
        Sai[i+1] = Sai[i] + a[i];
        Sxor[i+1] = Sxor[i] ^ a[i];

        //db3(i+1,Sai[i+1],Sxor[i+1]);
    }

    rep1(i,1,n+1){
        int p = n-i;
        int ap = a[p];

        int bitcnt=0;
        while(ap > 0){
            ap/=2;
            ++bitcnt;
        }
        mxor[p] = (1<<bitcnt)-1;
        if(i>1)chmax(mxor[p],mxor[p+1]);
    }
    //rep(i,n){db3(i+1,Sai[i+1],Sxor[i+1]);db(mxor[i]);ln;}

    rep(i,n){

        int st = i+1;
        int ed = n;
        int mid=(st+ed)/2;

        while(st+1 < ed){
            int xorlr = Sxor[mid]^Sxor[i];
            int sumlr = Sai[mid]-Sai[i];

            //db2(i+1,mid);db2(xorlr,sumlr);ln;

            if(xorlr==sumlr)st=mid;
            else ed = mid;
            mid=(st+ed)/2;

            //db3(st,mid,ed);ln;
        }

        ll r = mid-i;

        if(r > 0){
            ll add = r*(r+1)/2;
            //db3(i+1,mid,r);db(add);ln;
            ans += add;

            i = (mid-1);
        }else{
            //db2(i+1,i+1);ln;
            ++ans;
        }
    }

    cout<<ans<<endl;

    //cout <<fixed<<setprecision(16)<< << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
