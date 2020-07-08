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

std::chrono::system_clock::time_point start;
std::chrono::system_clock::time_point owari;

double TimeLeft(){
    owari = std::chrono::system_clock::now();
    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(owari-start).count();
    return elapsed;
}



int d=365;
int c[26]={};
int s[365][26]={};


struct sl{
    ll score=0;
    vector<int> arr;
    sl(){
        arr.resize(365);
    }
};


ll sigk(ll n){
    return n*(n+1)/2;
}

ll calcScore(sl old){

    ll ret = 0;
    rep(i,d){
        old.score += s[i][ old.arr[i] ];
        ret += s[i][ old.arr[i] ];
    }

    int lastheld[365]={};
    rep1(i,1,d+1){

        int today = old.arr[ i-1 ];
        int dur = i - lastheld[today];

        old.score -= sigk(dur-1)*c[today];
        ret -= sigk(dur-1)*c[today];

        lastheld[today] = i;
    }

    return ret;
}

int main(){

    start = std::chrono::system_clock::now(); //Timer start
    clock_t stt = clock();
    std::random_device rnd;

    bool flag=false;
    ll ans=0,sum=0;

    cin>>d;

    rep(i,26){
        cin>>c[i];
    }

    sl old;
    rep(i,d){
        int Conf=0,Tp=-1;
        rep(j,26){
            cin>>s[i][j];
            if(chmax(Conf,s[i][j]))Tp=j;
        }
        old.arr[i]=Tp;
    }

    old.score = calcScore(old);

    start = std::chrono::system_clock::now(); //Timer start
    stt = clock();

    clock_t now;
    while(1){
        sl nw = old;
        nw.score = 0;

        int cd = rnd()%d;
        int cT = rnd()%26;
        while(nw.arr[cd] == cT)cT = rnd()%26;

        nw.arr[cd] = cT;
        nw.score = calcScore(nw);

        if(nw.score > old.score){
            old = nw;
            cout<<old.score <<endl;
        }

        now = clock();
        //cout<<fixed<<setprecision(6)<<(double)(now - stt)/CLOCKS_PER_SEC<<endl;
        if((double)(now - stt)/CLOCKS_PER_SEC > 1.95)break;
    }

    //for(int ai:old.arr)cout<< ai+1 <<endl;

    //cout <<fixed<<setprecision(16)<< << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
