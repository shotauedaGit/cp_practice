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

//bool DBG=true;
bool DBG=false;

#define D 365
#define Tp 26

int c[Tp]={};
int s[D][Tp]={};



struct IHC{

    int itr=0,impl=0;
    ll outS=-INF,solS=-INF;
    int dur[D+1][Tp][3]={};//0:is contest held, 1:until this contest 2:next be held in...
    
    int output[D]={};
    int solution[D]={};

    void init(){
        if(!DBG){
            int d;
            cin>>d;
            rep(i,Tp)cin>>c[i];
            rep(i,D)rep(j,Tp){
                cin>>s[i][j];
            }
        }else{
            ifstream input("AHC\\IHC\\tester\\example\\sample2.in");
            int d;
            input>>d;
            rep(i,Tp)input>>c[i];
            rep(i,D)rep(j,Tp){
                input>>s[i][j];
            }
        }

        Timer_start();
    }

    void solve(){

        int init_itr = 100;
        rep(i,init_itr){
            rep(i,D)solution[i] = rand()%Tp;
            if(chmax(outS,all_eval()))rep(i,D){output[i] = solution[i];}
        }

        int freq=10;
        int init_itr2 = 1000;
        rep(i,init_itr2){
            rep(i,D){
                if((rand()%freq) == 0)solution[i] = rand()%Tp;
            }
            if(chmax(outS,all_eval()))rep(i,D){output[i] = solution[i];}
        }

        if(DBG)cout<<"rand change end : "<<Timer_end()<<"ms"<<endl;
        if(DBG)cout<<"outS "<<outS<<endl;

        rep(i,D)solution[i] = output[i];

        while(Timer_end() < 1900){
            itr++;

            // random change
            int chD = rand()%D,pastTp = solution[chD];
            int chTp = (rand() + solution[chD])%Tp;

            rep(i,1){
                if(c[pastTp] < c[chTp])break;
                chTp = (rand() + solution[chD])%Tp;
            }

            solution[chD] = chTp;
            solS = all_eval();

            if(chmax(outS,solS)){
                impl++;
                //cout<<"impl!! "<<itr<<endl;
                rep(i,D){output[i] = solution[i];}
                //if(DBG)cout<<"t: "<<Timer_end()<<" S: "<<outS<<endl;
            }else{
                solution[chD] = pastTp;
            }
        }

        if(DBG)cout<<"outS "<<outS<<endl;
    }

    ll all_eval(){
        ll evalS = 0;

        int last_held[Tp] = {};
        rep(i,Tp) last_held[i]=0;
        
        rep(i,D){
            int held = i+1;
            int type = solution[i];

            evalS += s[i][type];
            int d = i - last_held[type];
            evalS -= (d*(d+1)/2)*c[type];

            last_held[type] = held;
        }

        rep(i,Tp){
            int d = D - last_held[i];
            evalS -= (d*(d+1)/2)*c[i];
        }

        return evalS;
    }

    void out(){
        rep(i,D){
            if(!DBG)cout<<output[i] + 1<<endl;
        }

        if(DBG){
            cout<<"(itr/impl)="<<impl<<"/"<<itr<<" ("<< (double)impl/itr<<" )"<<endl;
            cout<<outS<<endl;
        }

    }
};


int main(){

    srand(time(NULL));
    IHC prob;
    prob.init();
    prob.solve();
    prob.out();


    return 0;
}
