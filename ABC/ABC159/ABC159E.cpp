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
    ll ans=LINF,sum=0;

    int h,w,klim;
    cin>>h>>w>>klim;

    vector<string> g(h);

    rep(i,h)cin>>g[i];

    bool dbM=false;

    rep(i,(1<<h-1)){ //水平方向の割りかた全探索
        ll tmp=0;
        
        int cur=i;
        vector<int> gl(h);gl[0]=0;

        if(dbM)cout<<"pat:   "<<i<<endl;
        rep(j,h-1){ //グループ分け

            if(dbM)cout<<j+1<<endl;

            if(cur%2){
                ++tmp;
                gl[j+1]=gl[j]+1;
                if(dbM)cout<<" =>"<<endl;
            }else{
                gl[j+1]=gl[j];
            }

            cur /= 2;
        }
        if(dbM)cout<<h<<"\n\n";

        int Glnum=tmp+1;

        vector<int>WhCnt(Glnum);
        vector<int>curWhCnt(Glnum);

        bool cont=false;
        bool div=false;


        int curWidth=0;
        rep(j,w){//横方向にみていく、毎回、そこに切れ目を入れるべきか判断

            fill(all(curWhCnt),0);
            rep(k,h){
                if(g[k][j]=='1'){
                    ++curWhCnt[gl[k]];
                }
            }

            cont=false;div=false;

            if(dbM)cout<<" ( ";
            rep(p,Glnum){
                
                int WhC=curWhCnt[p]+WhCnt[p];
                if(dbM)db2(p,WhC);

                if(WhC > klim){
                    div=true;
                    
                    rep(p,Glnum)if(curWhCnt[p]>klim)cont=true;

                }
            }
            if(dbM)cout<<"  ) ";
            if(cont){
                if(dbM)cout<<"cont at "<<j;
                break;//積んでいたら途中でも中断

            }

            if(div){
                curWidth=0;
                fill(all(WhCnt),0);
                ++tmp;
                if(dbM)cout<<"dvided"<<endl;
            }else{
                curWidth++;
                if(dbM)ln;
            }

            rep(p,Glnum)WhCnt[p]+=curWhCnt[p];
        }
        if(dbM)ln;

        if(cont){
            continue;
        }//水平方向の別の割り方を試しに行く 

        chmin(ans,tmp);
    }
    cout<<ans<<endl;
    
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
