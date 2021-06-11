#include <bits\stdc++.h>
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

chrono::system_clock::time_point  start;
void Timer_start(){start = std::chrono::system_clock::now();}
double Timer_end(){
    auto end = std::chrono::system_clock::now();
    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count(); //処理に要した時間をミリ秒に変換
    return elapsed;
}

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}

        // R D  L U
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int dx8[8] ={1,1,0,-1,-1,-1, 0, 1};
int dy8[8] ={0,1,1, 1, 0,-1,-1,-1};

const bool DBG = true;
//const bool DBG = false;
#define msg(x) if(DBG)cerr<<x<<endl;
#define msg(f,x) if(DBG)cerr<<"function:"<<f<<", "<<x<<endl;

class path{
    int a,b;
    int len;
    vector<P> edges;

}


class AHC003{
    public:
    const int W=30,H=30,Query=1000;

    const double r = 0.998;
    const double rPow[Query];

    int curQuery=0;
    int d[W*H][W*H] = {};

    int row[H] = {};
    int col[W] = {};

    inline int idx(int i,int j){return i*W+j;}
    inline int getDist(int idx1,int idx2){
        if(!((0<= idx1 && idx1<H*W)&&(0<=idx2 && idx2<H*W))){
            msg("getDist","out of bounds");
            return -1;
        }
        return d[idx1][idx2];
    }
    inline void setDist(int idx1,int idx2,int _d){
        if(!((0<= idx1 && idx1<H*W)&&(0<=idx2 && idx2<H*W))){
            msg("setDist","out of bounds");
        }else{
            d[idx1][idx2] = _d;
            d[idx2][idx1] = _d;
        }
    }

    void init();
    string path(int si,int sj,int ti,int tj);

};


void AHC003::init(){

}


int main(){
    return 0;
}