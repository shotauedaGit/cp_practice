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

    int n;
    cin>>n;

    unordered_map<int,vector<int>> g;
    unordered_map<int,int> vis;
    vis[0]=true;

    rep(i,n){
        int a,b;
        cin >>a>>b;--a;--b;

        vis[a]=0;vis[b]=0;

        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    /* hashmap all elements

    cerr<<"debug"<<endl;
    for(auto p:g){
        cerr<<p.fi+1<<": ";

        for(int nx:p.se){
            cerr<<nx+1<<" ";
        }
        cerr<<endl;
    }
    //*/


    queue<P> st;
    vis[0]=999;
    for(int nx:g[0]){
        st.push(P(0,nx));
    }

    while (!st.empty()){
        int frm = st.front().fi;
        int cur = st.front().se;
        st.pop();

        if(chmax(ans,cur)){}

        //db2(frm+1,cur+1);ln;

        for(int nx:g[cur]){

            if(vis[nx] != 999){
                st.push(P(cur,nx));
                vis[nx]=999;
            }
        }
    }

    cout<<ans+1<<endl;
    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    return 0;
}
