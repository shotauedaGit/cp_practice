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



vector<int> app(1000010,0);
vector<bool> is_prime(1000010,true);

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int n;
    cin>>n;
    vector<int> a(n);
    vector<bool> isNOTcoprime(n,false);

    rep(i,n){
        int ai;
        cin>>ai;
        a[i] = ai;
        app[ai]++;
    }

    ll g = gcd(a[0],a[1]);
    //db(g);ln;
    rep1(i,2,n){
        g = gcd(g,a[i]);
        //db(g);ln;
    }

    if(g != 1){
        cout<<"not coprime"<<endl;
        return 0;
    }

    //sort(all(a));
    bool p_cop = true;


    vector<int> prime;
    rep1(i,2,1000001){
        if(is_prime[i]){
            prime.emplace_back(i);

            int p = i*2;
            while(p <= 1000000){is_prime[p]=false;p+=i;}
        }
    }

    
    for(int pi : prime){
        int cnt = 0;
        int p = pi;
        
        while(p <= 1000001){
            if(app[p] != 0)++cnt;
            p += pi;
        }

        //db2(pi,cnt);ln;

        if(cnt >= 2)p_cop=false;
        if(!p_cop)break;
    }

    if(p_cop){
        cout<<"pairwise coprime"<<endl;
    }else{
        cout<<"setwise coprime"<<endl;
    }

    //cout <<fixed<<setprecision(16)<< << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
