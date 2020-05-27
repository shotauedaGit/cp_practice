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

class str{
    public:
    int mag=0;
    int mass=0;
    int type=0;
    long double score=0;

    str(){}
    str(int a,int b,int tp){
        mass = a;
        mag = b;
        type  = tp;

        score = (long double)b/a;
    }

};


bool cmp(str a,const str b){
    return (a.score > b.score);
}

int main(){

    bool flag=false;
    long double ans=0;

    int n,m;
    cin>>n>>m;
    vector<str> mst(n+m);

    rep(i,n){
        int a,b;
        cin>>a>>b;

        str mi(a,b,1);
        mst[i]=mi;
    }

    rep(i,m){
        int c,d;
        cin>>c>>d;

        str mi(c,d,2);
        mst[n+i]=mi;
    }

    sort(all(mst),cmp);

    int cnt=5,hlp=0;
    long double A=0,B=0;

    for(auto p:mst){
        /*
        if(cnt==0)break;

        if(p.type == 2){
            if(hlp==1)continue;
            hlp++;
        }

        A += p.mass;
        B += p.mag;
        */

        db3(p.score,p.mag,p.type);ln;

    }

    //cout<<B/A<<endl;
    cout <<fixed<<setprecision(16)<<B/A << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    return 0;
}
