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

//typedef pair<int,int> P;
//typedef pair<int,P> iP;
//typedef pair<P,P> PP;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return (a/gcd(a,b))*b;}

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


//typedef int score_type;
//typedef long long score_type;
typedef double score_type;

#define isDBG true
#define errPrint true

#define TLMS 1950.0

typedef struct Point{
    int x=0;
    int y=0;
    Point(){}
    Point(const Point &p):x(p.x),y(p.y){}
    Point(int _x,int _y):x(_x),y(_y){}
    Point operator=(const Point &p){
        x = p.x;
        y = p.y;
        return *(this);
    }
}P;

int dist(Point &s,Point &g){
    return abs(s.x - g.x)+abs(s.y - g.y);
};


#define N 1000
#define M 50
#define U 801
#define L 800

class param{
    public:
};

class state{
    public:
    ll t=0;
    score_type score=0;
    vector<int> r;

    unordered_map<int,int> s;
    unordered_map<int,int> g;

    vector<pair<P,pair<int,char> >> p;
    state(){
        r.resize(M,-1);
    }
    //double score;
};



class AHC006{
    public:

    int mdf=0,impd=0,fld=0;

    ifstream in_file;
    ofstream out_file,score_list;

    state s_best;
    param p;

    vector<P> Sp;
    vector<P> Gp;

    std::random_device rnd_dvc;
    std::mt19937 mt;

    P SG0;

    AHC006(char *_in_file/*,param &_p*/){
        mt = mt19937(rnd_dvc());

        in_file.open(_in_file);
        out_file.open("out.txt");
        score_list.open("score.txt",std::ios::app);
        
        //p = _p;
        SG0 = P(400,400);

        Sp.resize(N); Gp.resize(N);

        init();
    }

    void init(){
        
        int a,b,c,d;
        rep(i,N){
            if(isDBG)in_file>>a>>b;
            else cin>>a>>b;

            if(isDBG)in_file>>c>>d;
            else cin>>c>>d;

            Sp[i] = P(a,b);
            Gp[i] = P(c,d);
        }
    }

    //void s_init(state &s){}

    void first_state(){
        vector<pair<int,int>> d_sg(N);
        rep(i,N){
            d_sg[i].first = max(dist(SG0,Sp[i]) ,dist(SG0,Gp[i]));
            d_sg[i].second = i;
        }
        sort(all(d_sg));

        int pid;
        s_best.p.emplace_back(SG0,make_pair(-1,'s'));
        
        int cnt = 1;
        rep(i,M){
            pid = d_sg[i].second;
            s_best.r[i] = pid;
            s_best.p.emplace_back( Sp[pid] , make_pair(pid,'s') ); s_best.s[pid] = cnt; ++cnt;
            s_best.p.emplace_back( Gp[pid] , make_pair(pid,'g') ); s_best.g[pid] = cnt; ++cnt;
        }
        s_best.p.emplace_back(SG0,make_pair(-1,'g'));
        c_sc(s_best);

    }

    void modify(state &s/*,param &p*/,float temp){
        score_type new_score = -1,pre_score=-1;
        state s_mod(s);

        std::uniform_int_distribution<int> rndidx(1,100);
        int r1=rndidx(mt),r2=rndidx(mt);

        bool ok1 = true,ok2 = true;
        

        int r1idx = s.p[r1].second.first;
        char r1sg = s.p[r1].second.second;

        int r2idx = s.p[r2].second.first;
        char r2sg = s.p[r2].second.second;

        if(r1idx == r2idx){ok1=false;ok2=false;}

        if(r1sg == 's'){
            //cerr<<r1<<"=="<<s_mod.s[r1idx]<<endl;
            if(s.g[r1idx] < r2)ok1 = false;
        }else{
            //cerr<<r1<<"=="<<s_mod.g[r1idx]<<endl;
            if(s.s[r1idx] > r2)ok1 = false;
        }

        if(r2sg == 's'){
            //cerr<<r2<<"=="<<s_mod.s[r2idx]<<endl;

            if(s.g[r2idx] < r1)ok2 = false;
        }else{
            //cerr<<r2<<"=="<<s_mod.g[r2idx]<<endl;

            if(s.s[r2idx] > r1)ok2 = false;
        }

        if(ok1 && ok2){
            ++mdf;

            //cerr<<r1sg<<r1idx<<","<<r2sg<<r2idx<<" swapped"<<endl;
            //cerr<<r1sg<<r1idx<<" "; db2(s_mod.s[r1idx] , s_mod.g[r1idx]); cerr<<endl;
            //cerr<<r2sg<<r2idx<<" "; db2(s_mod.s[r2idx] , s_mod.g[r2idx]); cerr<<endl;

            pair<P,pair<int,char>> tmp;
            {
                tmp.first = s_mod.p[r1].first;
                tmp.second.first = s_mod.p[r1].second.first;
                tmp.second.second = s_mod.p[r1].second.second;

                s_mod.p[r1].first = s_mod.p[r2].first;
                s_mod.p[r1].second.first = s_mod.p[r2].second.first;
                s_mod.p[r1].second.second = s_mod.p[r2].second.second;

                s_mod.p[r2].first = tmp.first;
                s_mod.p[r2].second.first = tmp.second.first;
                s_mod.p[r2].second.second = tmp.second.second;
            }


            if(r1sg == 's'){ s_mod.s[r1idx] = r2;
            }else{ s_mod.g[r1idx] = r2; }

            if(r2sg == 's'){ s_mod.s[r2idx] = r1;
            }else{ s_mod.g[r2idx] = r1; }


            //cerr<<r1sg<<r1idx<<" "; db2(s_mod.s[r1idx] , s_mod.g[r1idx]); cerr<<endl;
            //cerr<<r2sg<<r2idx<<" "; db2(s_mod.s[r2idx] , s_mod.g[r2idx]); cerr<<endl;

            pre_score = s_best.score;
            new_score = c_sc(s_mod);

            if(new_score >= pre_score){
                ++impd;

            }else{
                ++fld;
            }

            float prob = exp((new_score-pre_score)/temp);
            std::uniform_int_distribution<> rnd(0,9999);
            
            if(rnd(mt) < prob*10000.0f){
                s_best = s_mod;
            }
        }
    }

    void solve(){

        first_state();
        
        output(s_best);

        while(Timer_end() < TLMS){
            float temp = ((TLMS-Timer_end())/TLMS)*300 + 1;
            modify(s_best,temp);
        }

        output(s_best);
    }

    score_type c_sc(state &s){
        score_type scr=0.0;
        ll t_sum=0;
        rep(i,(s.p.size())-1){
            t_sum += dist(s.p[i+1].first , s.p[i].first);
        }
        
        s.t = t_sum;
        scr = 1e8/(1e3+t_sum);
        s.score = scr;
        return scr;
    }

    //score_type c_sc_diff(state &s){}

    void output(state &s){
        out_file<<M;
        cout<<M;
        rep(i,M){
            out_file<<" "<<(s.r[i]+1);
            cout<<" "<<(s.r[i]+1);
        }
        out_file<<endl;
        cout<<endl;

        int n = s.p.size();
        out_file<<n;
        cout<<n;
        rep(i,n){
            out_file<<" "<<s.p[i].first.x<<" "<<s.p[i].first.y;
            cout<<" "<<s.p[i].first.x<<" "<<s.p[i].first.y;
        }
        out_file<<endl;
        cout<<endl;

        cerr<<"t: "<<s.t<<" score: "<<fixed<<setprecision(3)<<s.score<<endl;

        cerr<<"modify: "<<mdf<<" impl: "<<impd<<" faild: "<<fld<<endl;
        score_list<<fixed<<setprecision(3)<<s.score<<endl;

        /*
        out_file.close();
        score_list.close();
        */
    }
};

int main(int argc, char *argv[]){
    Timer_start();
    //int tgt_name = atoi(argv[0]);
    //cerr<<"file: "<<argv[1]<<endl;

    AHC006 p(argv[1]);
    p.solve();


    cerr<<"time: "<<Timer_end()<<endl;
    //cout<<ans<<endl;
    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout <<"Yes" <<endl;
    //else cout << "No" <<endl;
    return 0;
}
