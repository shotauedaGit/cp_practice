#include <bits/stdc++.h>
using namespace std;

#define INF 1001001001
#define LINF 1001001001001001001
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
typedef pair<int,int> pii;
typedef pair<pii,pii> ppii;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    bool flag=false;
    ll ans=0,sum=0;

    int n,m,k;
    cin >>n>>m>>k;

    vector<set<int>> blk(n),fnd(n);
    vector<vector<int>> fndTree(n);


    rep(i,m){
        int a,b;
        cin>>a>>b;
        --a;--b;

        fnd[a].insert(b);
        fnd[b].insert(a);

        fndTree[a].eb(b);
        fndTree[b].eb(a);

    }

    rep(i,k){
        int a,b;
        cin>>a>>b;
        --a;--b;

        fnd[a].insert(b);
        fnd[b].insert(a);
    }

    vector<int> glp(n,-1);
    int gln = 0;

    rep(i,n){
        if(glp[i]!=-1)continue;

        stack<int> st;
        st.push(i);

        while(!st.empty()){
            int cur = st.top();st.pop();

            rep(j , fndTree[i].size() ){
                int nx = fndTree[i][j];
                
            }


        }
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout<<ans<<endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
