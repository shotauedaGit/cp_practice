#include <bits/stdc++.h>
using namespace std;

//要りそうなやつ
#define se secondaa
#define fi first
#define all(a)  (a).begin(),(a).end()

typedef long long ll;

template<class T,class U>bool chmax(T &a, const U &b){if(a<b){a=b;return 1;}return 0;}
template<class T,class U>bool chmin(T &a, const U &b){if(b<a){a=b;return 1;}return 0;}


//ただの怠慢
#define db(x) cerr<<#x<<" = "<<x<<" ";
#define db2(x,y) cerr<<"("<<#x<<", "<<#y<<") = ("<<x<<", "<<y<<") ";
#define db3(x,y,z) cerr<<"("<<#x<<", "<<#y<<", "<<#z<<") = ("<<x<<", "<<y<<", "<<z<<") ";
#define ln cout<<endl;

#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)
#define rep1(i,a,b) for(int a_=(a),b_=(b),i=a_;i<b_;++i)
#define repr(i,n) for(int _i=(n),i=_i;i>0;--i)


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
        mInt ret(1),tmp(x);
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
    mInt operator/(const mInt &p)const{return mInt(*this) /= p;}
    bool operator==(const mInt &p)const{return x == p.x;}
    bool operator!=(const mInt &p)const{return x != p.x;}
};

int main(){
    mInt<13> m1(1);
    vector<mInt<13>>a(10);

    rep(i,2)cin>>a[i];
    ll a0=a[0].x;
    ll a1=a[1].x;

    cout<<a[0]<<"+"<<a[1]<<"="<<a[0]+a[1]<<" exact: "<< a0+a1;ln;
    cout<<a[0]<<"*"<<a[1]<<"="<<a[0]*a[1]<<" exact: "<< a0*a1;ln;
    cout<<a[0]<<"-"<<a[1]<<"="<<a[0]-a[1]<<" exact: "<< a0-a1;ln;
    cout<<a[0]<<"**"<<a[1]<<"="<< a[0].pow(a[1].x) <<" exact: "<< pow(a0,a1);ln;
    cout<<a[0]<<"/"<<a[1]<<"="<< a[0]/a[1] <<" (a[0]/a[1])*a[1] = "<<((a[0]/a[1])*a[1]);ln;

    return 0;
}