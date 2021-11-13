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
ll lcm(ll a,ll b){return (a/gcd(a,b))*b;}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int dx8[8] ={1,1,0,-1,-1,-1, 0, 1};
int dy8[8] ={0,1,1, 1, 0,-1,-1,-1};

chrono::system_clock::time_point  start;
void Timer_start(){start = std::chrono::system_clock::now();}
double Timer_end(){
    auto end = std::chrono::system_clock::now();
    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count(); //処理に要した時間をミリ秒に変換
    return elapsed;
}

class primes{
    public:
    int n=100;
    vector<bool> isp;
    vector<int> p;

    primes(){
        update(100);}
    primes(int _n){
        update(_n);
    }
    
    void update(int _n){
        n = _n;
        isp.resize(n+1,true);
        isp[0]=false;
        isp[1]=false;
        for(int i=2;i<=n;i++){
            if(isp[i]){
                int c = i*2;
                p.emplace_back(i);
                while(c <= n){isp[c]=false;c+=i;}
            }
        }
    }

    void dbg_prime(){
        for(int pi:p)cout<<pi<<" ";
        cout<<endl;
    }
};

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
    mInt(ll in,int m){x=absmod(in);mod=m;}
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
    mInt operator*(const ll &p)const{mInt<mod> mp;mp.x=p;return mInt(*this) *= mp;}

    mInt operator/(const mInt &p)const{return mInt(*this) /= p;}

    bool operator==(const mInt &p)const{return x == p.x;}
    bool operator!=(const mInt &p)const{return x != p.x;}
    bool operator>(const mInt &p)const{return x > p.x;}
    bool operator<(const mInt &p)const{return x < p.x;}
    bool operator>=(const mInt &p)const{return x >= p.x;}
    bool operator<=(const mInt &p)const{return x <= p.x;}
};


template<int mod=1000000007>
class noPreparemFact{
    public:
    int n;
    primes m_prime;
    mInt<mod> ans;

    noPreparemFact(int _n){
        n=_n; m_prime=primes(n);

        ans = 1;
        for(int pi: m_prime.p){
            int ppow=pi,pow=0,cnt=1;
            mInt<mod> mpi(pi);

            while(n/ppow > 0){
                pow += (n/ppow);
                cnt++;ppow*=pi;
            }

            if(pi<10)cout<<pi<<"^"<<pow<<" *"<<endl;
            ans *= mpi.pow(pow);
        }
        cout<<":"<<endl<<":"<<endl;

    }
};


int main(){

    bool flag=false;
    ll sum=0;

    int n;
    cin>>n;
    
    Timer_start();
    //noPreparemFact<MOD> npf(n);
    mInt<MOD> ans(1);
    for(int i=2;i<=n;++i){
        ans *= mInt<MOD>(i);
    }

    cout<<ans<<endl<<"time:"<<Timer_end()<<endl;


    //cout<<ans<<endl;
    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
