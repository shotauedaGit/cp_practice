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

char last1(char C1,char C2){
    if(C1=='R' && C2=='B' || C1=='B' && C2=='R')return 'G';
    else if(C1=='G' && C2=='B' || C1=='B' && C2=='G')return 'R';
    else return 'B';
}

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int n;
    string s;

    cin>>n>>s;
    vector<int>idxR;
    vector<int>idxG;
    vector<int>idxB;
    map<char,vector<int>> idx;

    rep(i,n){
        idx[s[i]].eb(i);

        switch (s[i]){
        case 'R':
            idxR.eb(i);
            break;

        case 'G':
            idxG.eb(i);
            break;

        case 'B':
            idxB.eb(i);
            break;

        default:
            break;
        }
    }

    ll rgb=0;

    rep(i,n){
        rep1(j,i+1,n){
            if(s[i] == s[j])continue;

            vector<int>idxN = idx[last1(s[i],s[j])];
            rgb += idxN.end() - upper_bound(all(idxN),j);
        }
    }

    ll DDDrgb=0;
    ll DDD=0;
    bool fin=false;
    for(int d=1;2*d<n;++d){

        int st=0,mid=st+d,ed=mid+d;
        for(st=0;ed<n;++st,++mid,++ed){
            ++DDD;
            if(! ( (s[st]==s[mid]) || (s[st]==s[ed]) || (s[ed]==s[mid]) ))++DDDrgb;
        }
    
    }

    //db3(rgb,DDD,DDDrgb);ln;
    cout<<rgb - DDDrgb <<endl;

    //cout <<fixed<<setprecision(16)<< << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
