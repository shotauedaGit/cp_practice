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


class cls{
    public:
    ll e=0;
    ll E=0;
    ll d_nE = INF;
    ll ha=0;

    cls(){}
    cls(ll _e,ll _E,ll _h):e(_e),E(_E),ha(_h){}
};

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int n,m;
    cin>>n;

    vector<ll> a(n+1);
    rep(i, n+1){
        cin>>a[i];
    }



    int st;
    vector< cls >arr(n+1);

    rep(d,30){
        arr[d].ha = a[d];
        arr[d].d_nE = ((1LL<<(d)) - arr[d].ha);// karigime
        arr[d].E = ((1LL<<(d)) - arr[d].ha);// karigime
    }

    rep(i,n+1){
        int d = n-i;

        arr[d].ha=a[d];
        
        if(d==n){
        
            //jimei
            arr[d].e=0;
            arr[d].E=0;
        
        }else{
            int nx=d+1;
            ll mx = arr[nx].ha + arr[nx].E;
            ll mn = (arr[nx].ha + arr[nx].e + 1)/2; // min res

            arr[d].e = mn; //first rect
            arr[d].E = mx;

            if(d < 30){

                chmin( arr[d].E , (1LL<<(d)) - arr[d].ha ); //red array
                chmin( arr[d].e , (1LL<<(d)) - arr[d].ha ); //red array
                
                if(arr[d].e == arr[d].E  &&  arr[d].e+arr[d].ha == (1LL<<(d+1)) ){
                    st = d;
                    arr[d].d_nE = arr[d].E;
                    break;

                }else if(arr[d].e > arr[d].E && arr[d].d_nE <= 0){
                    cout<<d<<endl;
                    cout<<-1<<endl;
                    return 0;
                }
            }
        }

        cout<<"d:"<<d;
        cout<<"  d_nE :"<<arr[d].d_nE;
        cout<<"  d_E :"<<arr[d].E;
        cout<<"  d_e :"<<arr[d].e;
        ln;
    }

    for(int i  = 1 ; i <= n; ++i){
        int pr = i-1;
        arr[i].d_nE = min( arr[i].E ,(arr[pr].d_nE)*2 - arr[i].ha);
    }

    rep(i,n+1){
        ll dne = arr[i].d_nE;
        ll h = arr[i].ha;
        
        cout<<dne<<" <- dne ha -> "<<h<<endl;

        ans += arr[i].d_nE + arr[i].ha;
    }
    cout<<ans<<endl;
    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    return 0;
}
