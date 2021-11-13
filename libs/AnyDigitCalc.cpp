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

int dx8[8] ={1,1,0,-1,-1,-1, 0, 1};
int dy8[8] ={0,1,1, 1, 0,-1,-1,-1};

chrono::system_clock::time_point  start;
void Timer_start(){start = std::chrono::system_clock::now();}
double Timer_end(){
    auto end = std::chrono::system_clock::now();
    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count(); //処理に要した時間をミリ秒に変換
    return elapsed;
}

class ADC{
    public:
    const static int digit=5000;
    vector<int> x;

    ADC(){assign();}
    ADC(string s){assign(s);}
    void assign(){x.resize(digit,0); fill(all(x),0);}
    void assign(string s){
        int cnt=0;
        x.resize(digit,0);
        reverse(all(s));
        for(auto si:s){
            if(cnt < digit)x[cnt] = (int)(si-'0');
            else break;
            cnt++;
        }
    }
    void roundUP(){
        rep(i,digit){
            if( i<digit-1 )x[i+1] += x[i]/10;
            x[i] %= 10;
        }
    }
    void Copy(const ADC &p){x = p.x;}
    ADC &operator=(const ADC &p){Copy(p); return *this;}

    ADC &operator+=(const ADC p){
        rep(i,digit){x[i] += p.x[i];}
        roundUP();
        return *this;
    }

    ADC operator+(const ADC &p)const{return (ADC(*this)+=p);}
    
    void AddShift(const ADC &p,int shift){
        rep(i,digit-shift){x[i+shift] += p.x[i];}
        roundUP();
    }

    ADC &operator*=(int d){
        rep(i,digit){x[i] *= d;}
        roundUP();
        return *this;
    }
    ADC operator*(const int d)const{return ADC(*this)*=d;}

    ADC &operator*=(const ADC p){
        ADC self(*this),add,mul;
        fill(all(x),0);

        rep(i,digit){
            mul=(self*p.x[i]);
            (*this).AddShift(mul,i);
        }
        return *this;
    }
    ADC operator*(const ADC &p)const{return ADC(*this)*=p;}

    ADC pow(int a){
        ADC self(*this),ret("1");
        if(a == 0){}
        else{
            while(a>0){
                if(a%2==1){
                    ret *= self;a--;
                }else{
                    self *= self;a/=2;
                }
                //cout<<ret<<"   "<<self<<"   "<<a<<endl;
            }
        }
        return ret;
    }

    friend istream &operator>>(istream &is, ADC &p) {
        string str; is >> str; p=ADC(str); return(is);
    }
    friend ostream &operator<<(ostream &os, const ADC &p) {
        string str;
        bool zero=true;
        rep(i,digit){
            if(zero==true && p.x[digit-1-i]!=0)zero=false;
            if(zero==false) str.push_back((char)('0'+p.x[digit-1-i]));
        }
        //reverse(all(str));
        return os<<str;
    }
};



int main(){

    ADC a,b;
    int c;

    cin>>a>>b>>c;

    cout<<a<<" + "<<b<<" =  "<<a+b<<endl;
    cout<<a<<" * "<<b<<" =  "<<a*b<<endl;
    cout<<a<<" ^ "<<c<<" =  "<<a.pow(c)<<endl;
    
    return 0;
}
