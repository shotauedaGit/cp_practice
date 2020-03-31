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
    ll ans=-1,sum=0;

    int n,m;
    cin >>n>>m;
    
    vector<pii>op(m);
    rep(i,m){
        int s,c;
        cin>>s>>c;
        pii em = {s,c};
        op[i] = em;
    }

    if(m==0){
        if(n==1)cout<<0<<endl;
        else if(n==2)cout<<10<<endl;
        else cout<<100<<endl;
        return 0;
    }

    int lim = (int)pow(10,n) + 10;
    //db(lim);ln;
    
    rep(i,lim){
        string num = to_string(i);
        //db(num);ln;

        bool jud=true;
        rep(j,m){

            if(op[j].fi > num.length() || num.length() != n){
                jud=false;
                break;
            }
            if(num[op[j].fi - 1] != '0' + op[j].se){
                jud=false;
                break;
            }
        }
        if(jud){
            ans=i;
            break;
        }
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout<<ans<<endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
