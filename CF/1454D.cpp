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





int main(){

    int t;cin>>t;

    rep(tcs,t){
        bool flag=false;
        ll n;
        unordered_map<ll,int> pf;
        cin>>n;

        int mx = -1;
        ll tmp=n;

        for(int i=2; i<=sqrt(n)+1; ++i){
            int cnt=0;
            while(tmp%i == 0){
                tmp/=i;
                cnt++;
            }

            if(cnt>0){
                pf[i] = cnt;
                chmax(mx,cnt);
            }
        }

        if(tmp > 1){
            pf[tmp] = 1;
            chmax(mx,1);
        }
        
        vector<ll> a(mx,1),b(mx,1);

        for(auto p:pf){
            if(p.se == mx)a[0] *= p.fi;
            else{
                b[ p.se ] *= p.fi;
            }
        }

        for(int i=1;i<b.size();++i){
            a[i] = a[i-1]*b[mx-i];
        }

        cout<<a.size()<<endl;
        rep(i,a.size())cout<<a[i]<<" ";
        cout<<endl;
    }


    

    //cout <<fixed<<setprecision(16)<< << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
