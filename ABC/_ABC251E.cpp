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

    int n;cin>>n;
    vector<ll> a(n,0);
    ll e_Sum=0,o_Sum=0;
    
    rep(i,n){
        cin>>a[i];
        if(i%2==0)o_Sum+=a[i];
        else e_Sum+=a[i];
    }


    vector<bool> cost(n,false);
    if(o_Sum < e_Sum){
        for(int i=0;i<n;i+=2)cost[i]=true;
    }else{
        for(int i=1;i<n;i+=2)cost[i]=true;
    }

    rep(i,n){
        if(cost[i] == false)continue;
        
        int prev = (i-1+n)%n;
        int next = (i+1)%n;

        if(cost[prev]){
            if(a[i] > a[next]){
                // 変更
                db2(i,next);
                cost[i] = false;
                cost[next] = true;
            }
        }else if(cost[next]){
            if(a[i] > a[prev]){
                // 変更
                db2(i,prev);

                cost[i] = false;
                cost[prev] = true;
            }
        }else{
            if(a[i] > a[next] + a[prev]){
                // 変更
                db3(i,next,prev);

                cost[i] = false;
                cost[next] = true;
                cost[prev] = true;
            }
        }
    }









    rep(i,n){
        if(cost[i])ans += a[i];
    }

    cout<<ans<<endl;

    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    return 0;
}
