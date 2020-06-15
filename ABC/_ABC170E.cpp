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





int main(){

    bool flag=false;
    ll ans=0,sum=0;
    int n,q;
    cin>>n>>q;

    multiset<int> mxRateInEachGlp;
    vector<multiset< int,greater<int>() >> vst(10);
    map<int,pair<int,int>> idx2rate_gln;

    rep(i,n){
        int a,b;
        cin>>a>>b;--b;
        vst[b].insert(a);
        idx2rate_gln[i] = {a,b};
    }

    rep(i , 200000){
        if(vst[i].size() > 0){
            int mxR = *(vst[i].begin());
            mxRateInEachGlp.insert(mxR);
        }
    }

    rep(i,q){
        int c,d;
        cin>>c>>d;
        --c;--d;

        int Ri = idx2rate_gln[c].first;
        int Glni = idx2rate_gln[c].second;


        int old_MnR_Glni = *(vst[Glni].begin());
        vst[Glni].erase(Ri);
        if( !vst[Glni].empty() ){
            int new_MnR_Glni = *(vst[Glni].begin());

            mxRateInEachGlp.insert(new_MnR_Glni);
        }
        mxRateInEachGlp.erase(old_MnR_Glni);


        if( !vst[d].empty() ){
            int old_MnR_d = *(vst[d].begin());
            mxRateInEachGlp.erase(old_MnR_d);
        }

        vst[d].insert(Ri);
        int new_MnR_d = *(vst[d].begin());

        mxRateInEachGlp.insert(new_MnR_d);

        cout<<*(mxRateInEachGlp.begin())<<endl;
    }

    //cout <<fixed<<setprecision(16)<< << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
