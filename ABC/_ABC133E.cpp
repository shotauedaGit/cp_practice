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

template<int mod=1000000007>
class mInt{
    public:
    int x;
    mInt() : x(0){}

    int absmod(ll in){
        if(in>=0)return in%mod;
        else return (in%mod)+mod;
    }
    mInt(ll in){x=absmod(in);}
    ~mInt(){}


    friend ostream &operator<<(ostream &os, const mInt &p) {return os << p.x;}
    friend istream &operator>>(istream &is, mInt &a) {
        int64_t t; is >> t;
        a = mInt<mod>(t); return(is);
    }

    mInt &operator+=(const mInt p){
        if((x += p.x) >= mod)x -= mod;
        return *this;
    }

    mInt &operator-=(const mInt p){
        if((x -= p.x) < 0)x += mod;
        return *this;
    }

    mInt &operator*=(const mInt p){x=(int)((ll)x*p.x%mod); return *this;}
    mInt &operator/=(const mInt p){x=(int)((ll)x*(p.pow(-1)).x%mod); return *this; }
    //mInt &operator=(const mInt p){x = p.x;return *this;}
    mInt &operator=(const ll p){x = absmod(p);return *this;}

    mInt pow(ll n)const{
        mInt<mod> ret(1),tmp(x);
        if(n==0)return ret;
        else if(n<0)n+=mod-1;

        while(n>1){
            if(n%2==0){n/=2;tmp*=tmp;}
            else {--n;ret*=tmp;}
        }
        ret *= tmp;return ret;
    }

    mInt operator+(const mInt &p)const{return mInt(*this) += p;}
    mInt operator-(const mInt &p)const{return mInt(*this) -= p;}
    
    mInt operator*(const mInt &p)const{return mInt(*this) *= p;}
    mInt operator*(const ll &p)const{mInt<mod>mp;mp.x=p;return mInt(*this) *= mp;}

    mInt operator/(const mInt &p)const{return mInt(*this) /= p;}

    bool operator==(const mInt &p)const{return x == p.x;}
    bool operator!=(const mInt &p)const{return x != p.x;}
    bool operator>(const mInt &p)const{return x > p.x;}
    bool operator<(const mInt &p)const{return x < p.x;}
    bool operator>=(const mInt &p)const{return x >= p.x;}
    bool operator<=(const mInt &p)const{return x <= p.x;}

    int pint(){return x;}
};

template<int mod=1000000007>
class mFact{
    public:
    int n;
    mFact() : n(1000){prepareFactArray();}
    mFact(int _n) : n(_n){prepareFactArray();}

    vector<mInt<mod>>fac;
    vector<mInt<mod>>fiv;

    void prepareFactArray(){
        fac.resize(n+10);
        fiv.resize(n+10);

        fac[0]=1;
        for(int i=1;i<=n;++i)fac[i] = fac[i-1]*i;

        fiv[n]=fac[n].pow(-1);
        for(int i=n;i>=0;--i)fiv[i-1] = fiv[i]*i;
    }

    
    mInt<mod> nCr(ll _n,ll r){
        mInt<mod> p(1),q(1),z(0);
        r=min(r,_n-r);
        if(r > _n)return z;
        if(_n > n){
            for(ll i=0;i<r;++i){p*=_n-i;q*=r-i;}
            return p/q;
        }
        else return fac[_n]*fiv[r]*fiv[_n-r];
    }
    //*/
};



int main(){

    bool flag=false;
    ll ans=0,sum=0;
    
    int n,k;
    cin>>n>>k;
    mFact<MOD> f(n);
    vector<vector<int>>g(n);
    vector<int> odim(n);
    vector<mInt<MOD>> pat(n);

    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        --a;--b;

        g[a].eb(b);
        g[b].eb(a);
    }

    /*
    rep(i,n){
        cout<<"node "<<i<<" :   ";
        for(int ch:g[i])cout<<ch<<" ";
        ln;
    }
    */

    queue<int> que;
    que.push(0);
    pat[0] = k;

    int par=-1;
    mInt<MOD> mans(0);

    vector<bool> vis(n,false);
    while(!que.empty()){
        int cur=que.front();
        vis[cur]=true;
        
        //db(cur);ln;
        que.pop();

        odim[cur] = g[cur].size();
        
        //db2(cur,odim[cur]);ln;
        //db(que.size());ln;

        if(odim[cur]==1 && cur!=0){
            mans += pat[cur];
            continue;
        }

        rep(j, odim[cur] ){
            int nex = g[cur][j];

            if(!vis[nex])que.push(nex);
            else continue;

            int mul = k - odim[cur];
            chmax(mul,0);

            pat[ nex ] = pat[cur]*mul;
            //db2( nex ,pat[ nex ]);ln;
        }
    }
    cout<<mans<<endl;
    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
