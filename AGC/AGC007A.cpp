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

typedef pair<int,int> P;
typedef pair<int,P> iP;
typedef pair<P,P> PP;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


int h=8,w=8;
vector<vector<char>> g(h,vector<char>(w));


bool bfs(int x,int y){

    //db2(x,y);
    if(g[y][x] == '.'){return false;}
    if(x == w-1&& y == h-1)return true;
    
    bool f1=false;
    bool f2=false;
    if(x < w-1){f1=bfs(x+1,y);}
    if(y < h-1){f2=bfs(x,y+1);}

    return f1 | f2;
}

int main(){
    bool flag=false;
    ll ans=0,sum=0;

    cin>>h>>w;

    int cnt=0;
    rep(i,h){
        rep(j,w){
            cin>>g[i][j];
            if(g[i][j]=='#')++cnt;
        }
    }

    if(cnt == h+w-1 && bfs(0,0)){
        cout<<"Possible"<<endl;
    }else{
        cout<<"Impossible"<<endl;
    }
    //cout <<fixed<<setprecision(16)<< << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
