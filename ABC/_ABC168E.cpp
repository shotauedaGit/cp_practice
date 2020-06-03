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
        if(r > _n)return z;

        r=min(r,_n-r);
        if(_n > n){
            for(ll i=0;i<r;++i){p*=_n-i;q*=r-i;}
            return p/q;
        }
        else return fac[_n]*fiv[r]*fiv[_n-r];
    }
    //*/
};

class frac{
    public:
    
    ll a=1;
    ll b=1;

    frac(){}
    frac(ll _a,ll _b):a(_a),b(_b){

        if(b==0){
            a=min(1LL,a);

        }else if(a==0){
            b=min(1LL,b);

        }else{
            a /= gcd(a,b);
            b /= gcd(a,b);
        }
    }

    frac hate(){
        return frac(b,a);
    }
};


int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int n,m;
    cin>>n;

    mInt<MOD>mAns(1);

    vector<ll> a(n),b(n);

    map<long double,pair<int,int>>arg;
    
    P axis(0,0);

    int z=0;
    rep(i,n){

        /*to do
        制度が足りなく、傾きは既約分数でもっておく

        */

        cin>>a[i]>>b[i];

        long double ai = a[i];
        long double bi = b[i];

        if(b[i] < 0){a[i]*=-1; b[i]*=-1;}
        frac a_b(a[i],b[i]); //分数の


        if(bi == 0){
            if(ai == 0){
                z++;
            }else{
                axis.fi++;
            }
        }else{
            long double t = ai/bi;
            arg[t].fi++;
        }
    }

    mInt<MOD> tw(2);

    for(auto p:arg){
        if(p.second.second == 1)continue;

        ld t = p.first;
        ld tinv = (ld)-1.0/t;

        int nQ = arg[tinv].first;
        int nP = p.second.first;

        arg[t].second=1;
        arg[tinv].second=1;

        //db2(t,nP);
        //db2(-tinv,nQ);
        //ln;

        mInt<MOD> mul = tw.pow(nQ) + tw.pow(nP) - 1;
        //cout<<"mlu:"<<mul<<endl;
        mAns *= mul;
    }

    int nZ = arg[0.0].first;
    int nVert = axis.first;

    mAns *= tw.pow(nZ) + tw.pow(nVert) - 1;
    mAns += z-1;
    cout<<mAns<<endl;

    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
