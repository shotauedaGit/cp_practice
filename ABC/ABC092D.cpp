#include <bits/stdc++.h>
using namespace std;

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





int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int a,b;
    cin>>a>>b;
    --a;--b;

    cout<<"80 80"<<endl;

    char g[80][80];


    rep(i,80){
        char c;

        if(i<40)c='#';
        else c='.';

        rep(j,80)g[i][j]=c;
    }


    bool br=false;
    for(int i=0; i<40; i+=2){
        
        for(int j=0;j<80;j+=2){
            if(a==0){br=true;break;}
            g[i][j] = '.';
            --a;
        }

        if(br)break;
    }

    br=false;
    for(int i=41;i<80;i+=2){
        
        for(int j=0;j<80;j+=2){
            if(b==0){br=true;break;}
            g[i][j] = '#';
            --b;
        }

        if(br)break;
    }


    rep(i,80){
        rep(j,80){
            cout<<g[i][j];
        }
        ln;
    }


    //cout <<fixed<<setprecision(16)<< << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
