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

int dx8[8] ={1,1,0,-1,-1,-1, 0, 1};
int dy8[8] ={0,1,1, 1, 0,-1,-1,-1};

chrono::system_clock::time_point  start;
void Timer_start(){start = std::chrono::system_clock::now();}
double Timer_end(){
    auto end = std::chrono::system_clock::now();
    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count(); //処理に要した時間をミリ秒に変換
    return elapsed;
}

ll a[10][10]={};
unordered_set<int> ng;

vector<int> t_arr(vector<int> p1,int offset){
    vector<int> ts;
    do{
        bool cont=false;
        int t = 0;
        rep(i , p1.size()-1){
            int ngi = p1[offset+i]*10 + p1[offset+i+1];
            if(ng.find(ngi) != ng.end()){cont=true;break;}
        }
        if(cont)continue;
        rep(i,p1.size())t += a[offset+p1[i]][offset+i];
        ts.emplace_back(t);

    }while(next_permutation(all(p1)));
    return ts;
}

//所要時間と走順をpairにして返す仕様にする
//mainない、前半後半の境目にNGpairがいたら、統合の際に追加しない。

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int n;cin>>n;
    rep(i,n)rep(j,n){
        cin>>a[i][j];
    }

    int m;cin>>m;
    rep(i,m){
        int x,y;cin>>x>>y;
        ng.insert(10*x + y);
        ng.insert(10*y + x);
    }

    vector<int> p1(n/2),p2(n-(n/2));
    rep(i,n/2)p1[i]=i;
    rep(i,n-(n/2))p2[i]=i;

    //変える
    vector<int> ts1 = t_arr(p1,0);
    vector<int> ts2 = t_arr(p2,n/2);

    vector<int> ts;
    rep(i , ts1.size()){
        rep(j , ts2.size()){

            cout<<ts1[i]<<" "<<ts2[j]<<endl;
            if(){
                ts.emplace_back(ts1[i] + ts2[j]);
            }
        }
    }

    sort(all(ts));
    if(ts.empty())cout<<-1<<endl;
    else cout<<ts[0]<<endl;

    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    return 0;
}
