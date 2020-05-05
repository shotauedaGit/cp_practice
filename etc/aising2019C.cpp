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

typedef pair<int,int> P;
typedef pair<int,P> iP;
typedef pair<P,P> PP;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int w,h;
    cin>>h>>w;
    vector<string> g(h);

    rep(i,h)cin>>g[i];

    vector<vector<bool>> vis(h,vector<bool>(w,false));

    rep(i,h)rep(j,w){

        if(g[i][j] == '#' && !vis[i][j] ){
            P now = P(i,j);

            stack<P> st;
            st.push(now);
            vis[i][j] = true;

            ll bl=0,wh=0;

            while(!st.empty()){
                P cur = st.top();st.pop();
                
                int ci = cur.fi;
                int cj = cur.se;

                //db3(ci,cj,g[ci][cj]);ln;

                if(g[ci][cj]=='#'){
                    bl++;
                }else{
                    wh++;
                }

                rep(k,4){
                    int ni = ci+dy[k];
                    int nj = cj+dx[k];

                    if(!(0<=ni && ni<h && 0<=nj && nj<w))continue;

                    //db2(k,st.size());db2(ni,nj)ln;

                    if(g[ni][nj]!=g[ci][cj] && !vis[ni][nj]){
                        P nx = P(ni,nj);
                        st.push(nx);
                        vis[ni][nj] = true;
                    }
                }

                //cout<<ci<<" "<<cj;ln;
            }

            //db2(bl,wh);ln;
            ans += bl*wh;
        }
    }

    cout<<ans<<endl;
    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
