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
    ll ans=LINF,sum=0;

    int h,w,klim;
    cin>>h>>w>>klim;

    vector<string> g(h);

    rep(i,h)cin>>g[i];


    rep(i,(1<<h-1)){

        int p=i,gr=1;

        vector<int>hdiv(h);
        vector<int>vdivpos(w);

        rep(k,h-1){
            if(p%2){hdiv[k]=gr;++gr;}
            else hdiv[k]=gr;
        }
        hdiv[h-1]=gr;

        vector<int> whcnt(gr,0);
        int j=0;
        int divcnt=gr;

        bool done=true;
        while(j<w){
            rep(k,h)if(g[k][j]=='1')whcnt[hdiv[k]]++;

            bool safe=true;
            rep(k,gr)if(whcnt[k]>klim)safe=false;

            if(!safe){
                if(!vdivpos.empty() && vdivpos.back() == j-1){done=false;break;}

                fill(all(whcnt),0);
                vdivpos.eb(j);
                divcnt++;
            }

            ++j;
        }

        if(done)chmin(ans,divcnt);
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    
    cout<<ans<<endl;
    
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
