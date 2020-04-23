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
    char ans;

    string a,b,c;
    queue<char> qa,qb,qc;
    cin>>a>>b>>c;

    rep(i,a.length())qa.push(a[i]);
    rep(i,b.length())qb.push(b[i]);
    rep(i,c.length())qc.push(c[i]);

    int turn=0;
    bool fin=false;

    while(!fin){
        char now;
        
        //db2(now,turn);
        //db3(qa.size(),qb.size(),qc.size());ln;

        switch(turn){
            case 0: if(qa.empty()){fin=true;ans='A';} now=qa.front();qa.pop();break;
            case 1: if(qb.empty()){fin=true;ans='B';} now=qb.front();qb.pop();break;
            case 2: if(qc.empty()){fin=true;ans='C';} now=qc.front();qc.pop();break;
            default : break;
        }

        switch(now){
            case 'a':turn=0;break;
            case 'b':turn=1;break;
            case 'c':turn=2;break;
            default : break;
        }
    }
    cout<<ans<<endl;

    //cout <<fixed<<setprecision(16)<< << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
