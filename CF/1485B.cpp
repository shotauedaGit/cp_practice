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
    bool flag=false;
    ll ans=0,sum=0;

    int n,q;ll k;
    cin>>n>>q>>k;

    vector<ll> a(n);
    vector<ll> s(n);
    
    rep(i,n)cin>>a[i];

    s[0] = a[1] - 2;
    if(n==1)s[0] = k-1;
    //cout<<1<<" :"<<a[0]-1<<" self "<<a[1]-a[0]-1<<endl;

    rep1(i,1,n-1){
        s[i] = s[i-1] + a[i+1] - a[i-1] - 2;
        //cout<<i+1<<" :"<<a[i]-a[i-1]-1<<" self "<<a[i+1]-a[i]-1<<endl;
    }
    
    if(n!=1)s[n-1] = s[n-2] + k - a[n-2] - 1;
    
    //cout<<n<<" :"<<a[n-1]-a[n-2]-1<<" self "<<k-a[n-1]<<endl;



    rep(i,q){
        int li,ri;
        cin>>li>>ri;li--;ri--;

        ll pat=0;
        if(li==0){
            pat = s[ri];
        }
        else {
            pat = s[ri] - s[li-1];
        }

        //cout<<"pat :"<<pat<<" + ";

        ll add=0;
        if(li!=0)add += a[li-1];
        if(ri!=n-1)add += -a[ri+1]+k+1;
        
        pat+=add;
        //cout<<add<<endl;

        cout<<pat<<endl;
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    return 0;
}
