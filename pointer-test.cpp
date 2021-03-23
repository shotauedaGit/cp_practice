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
typedef long double ld;

typedef pair<int,int> P;
typedef pair<int,P> iP;
typedef pair<P,P> PP;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

struct str_test{
    int id = -1;
    str_test *nx = NULL;

    str_test(){};
    str_test(int _id):id(_id){};
    str_test(int _id,str_test *_nx):id(_id),nx(_nx){};
};


class Mystr{
    public:
    int val = -1;
    Mystr(){}
    Mystr(int _v){val =_v;}
};

class tst{
    public:
    Mystr a,b,c;
    tst(){
        a = Mystr(1);
        b = Mystr(2);
        c = Mystr(3);
    }

    Mystr& fetch_a(){
        return a;
    }

    void fetch_a2(Mystr &a){
        a = fetch_a();
    }
};






int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int n,m;

    str_test s1(1);
    str_test s2(2);
    str_test s3(3);

    s1.nx = &s2;
    s2.nx = &s3;
    s3.nx = &s1;
    /*
    db3(&s1,&s2,&s3);ln;
    db3(s1.nx,s2.nx,s3.nx);ln;
    db3((*(s1.nx)).nx,(*(s2.nx)).nx,(*(s3.nx)).nx);ln;
    */

    tst test_str;
    Mystr d(999);
    Mystr A1(99),&A12 = d,&A12_1 = d;

    //A1 = test_str.fetch_a();
    test_str.fetch_a2(A12);
    //test_str.fetch_a2(A12_1);

    cout<<"A1 ="<<A1.val<<endl;
    cout<<"A12 ="<<A12.val<<endl;
    cout<<"A12 ="<<A12_1.val<<endl;

    

    //cout<<ans<<endl;

    //cout <<fixed<<setprecision(16)<< << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
