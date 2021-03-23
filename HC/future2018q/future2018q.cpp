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

#define Pnum 1000
#define Nnum 100

int input[Nnum][Nnum]={};

struct Sol{
    ll diff = -1;
    int op[Pnum][3];

    void copy(const Sol &src){
        diff = src.diff;
        rep(i,Pnum){
            op[i][0]=src.op[i][0]; op[i][1]=src.op[i][1]; op[i][2]=src.op[i][2];
        }
    }

    Sol& operator=(const Sol &src){
        this->copy(src);
        return *this;
    }

    Sol(){
        //cout<<"sol constructor"<<endl;
        rep(i,Pnum){
            op[i][0] = rand()%Nnum;
            op[i][1] = rand()%Nnum;
            op[i][2] = (rand()%Nnum)+1;
        }
    }

    bool is_out(int x,int y){
        if(!(0<=x&&x<Nnum && 0<=y&&y<Nnum))return true;
        return false;
    }

    void randomize(){
        //cout<<"randmoize begin"<<endl;
        rep(i,Pnum){
            op[i][0] = rand()%Nnum;
            op[i][1] = rand()%Nnum;
            op[i][2] = (rand()%Nnum)+1;
        }
        //cout<<"randmoize end"<<endl;
    }

    void eval(){

        //cout<<"eval:data "<<endl;
        
        int g[Nnum][Nnum]={};
        int dx[4]={1,-1,-1,1};
        int dy[4]={-1,-1,1,1};

        //cout<<"eval:simu begin"<<endl;


        rep(i,Pnum){
            int x = op[i][0];
            int y = op[i][1];
            int h = op[i][2];
            //cout<<x<<" "<<y<<" "<<h<<endl;

            g[x][y]+=h;

            for(int j=1;j<h;j++){
                int cx = x;
                int cy = y + j;

                rep(di,4){
                    rep(k,j){ 
                        cx += dx[di];cy += dy[di];
                        if(is_out(cx,cy)==false){
                            g[cx][cy] += h-j;
                            //cout<<"add:"<<cx<<" "<<cy<<" "<<g[cx][cy]<<endl;
                        }
                    }
                }
            
            }
        }

        //cout<<"eval:simu done"<<endl;

        diff=0;
        rep(i,Nnum){
            rep(j,Nnum){
                diff += abs(input[i][j] - g[i][j]);
            }
        }
        //cout<<"eval:calc done"<<endl;

    }
};

struct future2018q{
    
    Sol solution,bestSOl;

    future2018q(): solution(),bestSOl(){}
    
    void init(){
        srand(time(NULL));
        int a;
        rep(i,Nnum){
            rep(j,Nnum){
                cin>>a;
                input[i][j]=a;
            }
        }
        //cout<<"input done"<<endl;
    }

    void solve(){
        //cout<<"slv:begin "<<endl;
        
        solution.randomize();

        //cout<<"slv:eval begin "<<endl;
        solution.eval();
        
        bestSOl = solution;
        
        Timer_start();
        //cout<<"ms:"<<Timer_end()<<endl;

        priority_queue<ll,vector<ll>,greater<ll>> score;

        while (Timer_end() < 5500){
            //cout<<"ms:"<<Timer_end()<<endl;
            score.push(solution.diff);

            solution.randomize();
            solution.eval();
            //cout<<"score:"<<solution.diff;
            if(solution.diff < bestSOl.diff){
                bestSOl = solution;
                //cout<<"(best)";
            }
            //cout<<endl
        }


        ofstream ofs_rank("HC\\future2018q\\top10.txt", ios::app);
        cout<<"top 10 ranking"<<endl;
        
        int ranking=30;
        rep(i,ranking){
            ofs_rank<<score.top();
            if(i+1!=ranking)ofs_rank<<",";

            cout<<score.top()<<endl;
            score.pop();
        }
        ofs_rank<<endl;

    }

    void out(){
        cout<<Pnum<<endl;
        rep(i,Pnum){
            int x=bestSOl.op[i][0];
            int y=bestSOl.op[i][1];
            int h=bestSOl.op[i][2];
            //cout<<x<<" "<<y<<" "<<h<<endl;
        }
    }
};



int main(){

    future2018q prob;
    
    prob.init();
    rep(i,20)prob.solve();
    prob.out();

    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
