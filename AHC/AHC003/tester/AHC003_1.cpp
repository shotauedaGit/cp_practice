#include <bits\stdc++.h>
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

#define msg(x) if(DBG)cerr<<x<<endl;
#define msg(f,x) if(DBG)cerr<<"function:"<<f<<", "<<x<<endl;

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

chrono::system_clock::time_point  start;
void Timer_start(){start = std::chrono::system_clock::now();}
double Timer_end(){
    auto end = std::chrono::system_clock::now();
    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count(); //処理に要した時間をミリ秒に変換
    return elapsed;
}

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}

        // R D  L U
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int dx8[8] ={1,1,0,-1,-1,-1, 0, 1};
int dy8[8] ={0,1,1, 1, 0,-1,-1,-1};

const bool DBG = true;
//const bool DBG = false;
#define W 30
#define H 30
char dc[4] = {'R','D','L','U'};

class path{
    public:
    int id=-1,a=-1,cSum=-1;
    double r;
    vector<int> edges;
    double calcVal(){
        return 1;
    }
};
class pos{
    pos(int _i,int _j){i=_i;j=_j;}
    int i=-1,j=-1;
};
class edgeInfo{
    public:
    int frm=-1,to=-1;
    int eCost=-1;
    vector<int> paths;
    
};
class line{
    public:
    int bCost=-1;
    vector<P> edges;
};


class AHC003{
    public:
    vector<vector<edgeInfo>> edges;
    vector<path> paths;
    

    AHC003(){
        vector<vector<edgeInfo>> tmp((W)*(H),vector<edgeInfo>(2));
        edges = tmp;
        rep(i,W*H){
            edges[i][0].eCost = i;
            edges[i][1].eCost = i*2;
        }
    }
    void init(){}

    int E(pair<pair<int,int>,char> eInfo,edgeInfo &ebuf);
    
    pair< pair<int,int> ,char> cvt(int idx1,int idx2);
    pair< pair<int,int> ,char> cvt(int _idx,char di);
    pair< pair<int,int> ,char> cvt(int i,int j,char di);

    inline int idx(int i,int j){
        if( ((0<=i && i<H)&&(0<=j && j<W))){
            return (i*W+j);
        }else{
            return -1;
        }
        
    }
    inline bool on(int i,int j){
        if(0<=i && i<H && 0<=j && j<W)return true;
        else return false;
    }
};

int AHC003::E(pair< pair<int,int> ,char> eInfo,edgeInfo &ebuf){
    int i = eInfo.fi.fi;
    int j = eInfo.fi.se;
    char di = eInfo.se;

    if((i==-1  || j==-1)||(di!='R'&&di!='D')){
        if(DBG)cout<<"E:"<<i<<","<<j<<" di: "<<di<<"(invalid input)"<<endl;
        return -1;
    }

    if(di == 'R'){
        if(on(i,j) && on(i,j+1)){
            if(DBG)cout<<"E:"<<i<<","<<j<<" di: "<<di<<endl;
            ebuf = edges[idx(i,j)][0];
            return 1;
        }
    }else if(di == 'D'){
        if(on(i,j) && on(i+1,j)){
            if(DBG)cout<<"E:"<<i<<","<<j<<" di: "<<di<<endl;
            ebuf = edges[idx(i,j)][1];
            return 1;
        }
    }

    if(DBG)cout<<"exp E:"<<i<<","<<j<<" di: "<<di<<endl;
    return -1;
}
pair< pair<int,int> ,char> AHC003::cvt(int _idx,char di){
    pair< pair<int,int> ,char> ret;
    ret.fi = P(_idx/W,_idx%W);
    
    switch(di){
        case 'R': ret.se = di;break;
        case 'D': ret.se = di;break;

        case 'L':
            ret.fi.se -= 1;
            ret.se = 'R';
            break;
        
        case 'U':
            ret.fi.fi -= 1;
            ret.se = 'D';
            break;
    }

    return ret;
}
pair< pair<int,int> ,char> AHC003::cvt(int i,int j,char di){
    pair< pair<int,int> ,char> ret;
    ret.fi = P(i,j);

        switch(di){
        case 'R': ret.se = di;break;
        case 'D': ret.se = di;break;

        case 'L':
            ret.fi.se -= 1;
            ret.se = 'R';
            break;
        
        case 'U':
            ret.fi.fi -= 1;
            ret.se = 'D';
            break;
    }

    return ret;
}


int main(void){
    AHC003 t;t.init();

    edgeInfo buf;
    int i,j;char c;

    cin>>i>>j>>c;
    int ret = t.E(t.cvt(i,j,c),buf);
    cout<<ret<<" "<<buf.eCost<<endl;

    return 0;
}
