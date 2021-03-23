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

vector<bool> vis(200010,false);
vector<vector<int>> g(200010);

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int n,m;
    cin>>n>>m;

    set<P> rel;

    rep(i,m){
        int a,b;
        cin>>a>>b;
        --a;--b;

        if(rel.find(P(a,b))!=rel.end() || rel.find(P(b,a))!=rel.end())continue;

        g[a].emplace_back(b);rel.insert(P(a,b));//db2(a,b);ln;
        g[b].emplace_back(a);rel.insert(P(b,a));//db2(b,a);ln;

    }

    int mx_n = -1;
    rep(i,n){
        if(vis[i])continue;

        int n_connected_element = 1;
        stack<int> st;
        st.push(i);
        vis[i] = true;

        while(!st.empty()){
            int cur = st.top();st.pop();

            for(int j = 0 ; j < g[cur].size(); ++j){
                int nx = g[cur][j];

                if(vis[nx])continue;

                //db2(cur,nx);ln;

                st.push(nx);
                vis[nx] = true;
                ++n_connected_element;
            }
        }

        chmax(mx_n,n_connected_element);
    }

    cout<<mx_n<<endl;

    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    return 0;
}
