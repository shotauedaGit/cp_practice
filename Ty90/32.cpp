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




int main(){
    bool flag=false;
    ll ans=0,sum=0;

    int n,m;
    int a[10][10]={};
    vector<P> p;

    cin>>n;
    rep(i,n){
        rep(j,n){
        cin>>a[i][j];
        }
    }



    cin>>m;
    int hsh_tb[10000] = {};
    rep(i,m){
        int xi,yi;
        cin>>xi>>yi;
        --xi;--yi;

        hsh_tb[xi + yi*100] = 1;
        hsh_tb[yi + xi*100] = 1;
    }

    vector<int> ordr;
    rep(i,n)ordr.emplace_back(i);

    int ti=0,tmin=INF;
    int cnt=0;
    do{ 
        ++cnt;
        //cout<<a[0][ordr[0]]<<endl;
        ti = a[0][ordr[0]];
        bool ok=true;

        for(int i=1;i<n;++i){

            int hsh = ordr[i-1] + ordr[i]*100;
            if(hsh_tb[hsh] == 1){
                ok = false;
                continue;
            }

            ti += a[i][ordr[i]];
        }

        if(ok)chmin(tmin,ti);
    }while(next_permutation(all(ordr)));

    if(tmin == INF)cout<<-1<<endl;
    else cout<<tmin<<endl;

    db(cnt);
    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    return 0;
}
