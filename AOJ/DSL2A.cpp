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

class segtree{

    public:
    int N;
    ll init_val;
    vector<ll>dat;

    segtree(int _n,ll _init_val):init_val(_init_val){
        N=1;while(N < _n)N*=2;
        dat.resize(2*N - 1,_init_val);
    }

    void error_op(){cout<<init_val<<endl;}//クエリの例外処理

    void UpD_RMQ(int k,ll a){
        k += N-1;dat[k]=a;
        while(k > 0){
            k = (k-1)/2;//親へ移動
            dat[k] = min( dat[2*k+1],dat[2*k+2] );//子を比較(片方はさっき更新したやつ)
        }
    }

    void UpD_RSQ(int k,ll add){
        k += N-1;dat[k]+=add;
        while(k > 0){
            k=(k-1)/2; dat[k]+=add;
        }
    }

    ll Query_RSQ(int st,int ed,int idx,int l,int r){//st<=x<edのRSQを返す  ※dat[idx]は、l<=idx<rのクエリを持つ。
        //db3(dat[idx],l,r);ln;
        
        if(r <=st || ed <= l){return init_val;}
        else if(st <= l && r <= ed)return dat[idx];//答えが判明するのはここ
        else{
            ll ar = Query_RSQ(st,ed,idx*2 + 1, l , (l+r)/2 );
            ll al = Query_RSQ(st,ed,idx*2 + 2, (l+r)/2 , r);
            return ar+al;
        }
    }
    ll Query_RMQ(int st,int ed,int idx,int l,int r){//st<=x<edのRMQを返す  ※dat[idx]は、l<=idx<rのクエリを持つ。
        //db3(dat[idx],l,r);ln;
        if(r <=st || ed <= l){return init_val;}
        else if(st<=l && r<=ed)return dat[idx];//答えが判明するのはここ
        else{
            ll ar = Query_RMQ(st,ed,idx*2 + 1, l , (l+r)/2 );//子へ再帰的にクエリを渡す
            ll al = Query_RMQ(st,ed,idx*2 + 2, (l+r)/2 , r );//
            return min(ar,al);
        }
    }

};

int main(){

    ll ans=0;
    int n,q;
    cin>>n>>q;

    segtree sgt(n,INF);
    //db(sgt.N);ln;

    rep(i,q){
        int com;
        cin>>com;

        if(com==0){
            int i,x;
            cin>>i>>x;
            sgt.UpD_RMQ(i,x);
        }else{
            int s,t;
            cin>>s>>t;++t;
            cout << sgt.Query_RMQ(s,t,0,0,(sgt.N)) <<endl;
        }
    }

    //cout<<ans<<endl;
    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    return 0;
}
