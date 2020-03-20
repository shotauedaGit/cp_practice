#include <bits/stdc++.h>
using namespace std;

//要りそうなやつ

#define se second
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

    mInt &operator*=(const mInt p){x=(int)((ll)x*p.x % mod); return *this;}
    mInt &operator/=(const mInt p){x*=p.pow(-1); return *this}
    mInt &operator=(const ll p){x = absmod(p);return *this;}

    mInt pow(ll n){
        mInt ret(1);

    }

    mInt operator+(const mInt &p)const{return mInt(*this) += p;}
    mInt operator-(const mInt &p)const{return mInt(*this) -= p;}
    mInt operator*(const mInt &p)const{return mInt(*this) *= p;}
    mInt operator/(const mInt &p)const{return mInt(*this) /= p;}
    bool operator==(const mInt &p)const{return x == p.x;}
    bool operator!=(const mInt &p)const{return x != p.x;}

};


int main(){
    mInt<100> md1(87186584),md2(54353413),md3(25452524);





}


