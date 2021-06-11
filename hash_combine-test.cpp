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
typedef long double ld;

typedef pair<int,int> P;
typedef pair<int,P> iP;
typedef pair<P,P> PP;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

/*
struct str_test{
    int id = -1;
    str_test *nx = NULL;

    str_test(){};
    str_test(int _id):id(_id){};
    str_test(int _id,str_test *_nx):id(_id),nx(_nx){};
};
*/

size_t hash_v(int h1,int h2,int h3){
    size_t seed = 0;
    seed ^= h1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    seed ^= h2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    seed ^= h3 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    return seed;
}


int main(){
    bool flag=false;
    ll ans=0,sum=0;

    int n,m;
    cin>>n;

    unordered_map<ll,int> hsh_mp;

    auto not_find = hsh_mp.end();
    ll cnt = 0;

    rep(i,n+1){
        rep(j,n+1){
            rep(k,n+1){

                if( hsh_mp[hash_v(i,j,k)] != 0){
                    //cout<<" ############### "<<endl;
                    db3(i,j,k);cout<<"occurs collision";
                    cout<<"   hash : "<<hash_v(i,j,k)<<endl;
                }

                hsh_mp[hash_v(i,j,k)] = ++cnt;
            }
        }

        if(i % 100 == 0){
            //cout<<cnt<<"  pairs done"<<endl;
        }
    }

    cout<<cnt<<"  pairs done"<<endl;



    //cout<<ans<<endl;
    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}