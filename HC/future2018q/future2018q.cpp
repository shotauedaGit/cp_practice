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

bool DBG = false;
int input[Nnum][Nnum]={};

//bool operator<(const Sol& a, const Sol& b)const{return (a.diff < b.diff);}
//bool operator>(const Sol& a, const Sol& b)const{return (a.diff > b.diff);}

struct Sol{
    ll diff = -1;
    int op[Pnum][3];
    bool changed[Pnum];

    void copy(const Sol &src){
        diff = src.diff;
        rep(i,Pnum){
            op[i][0]=src.op[i][0]; op[i][1]=src.op[i][1]; op[i][2]=src.op[i][2];
            changed[i]=true;
        }
    }

    Sol& operator=(const Sol &src){
        this->copy(src);
        return *this;
    }
    bool operator<(const Sol& src)const{return (diff < src.diff);}
    bool operator>(const Sol& src)const{return (diff > src.diff);}
    
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

    void change_little(int p_change,int h_change,double prob){
        bool change = (rand() < RAND_MAX*prob);

        rep(i,Pnum){
            change = (rand() < RAND_MAX*prob);
            changed[i] = change;
            if(!change)continue;

            int ch_x = rand()%(2*p_change+1) - p_change;
            int ch_y = rand()%(2*p_change+1) - p_change;
            int ch_h = rand()%(2*h_change+1) - h_change;
            
            op[i][0] += ch_x;
            op[i][1] += ch_y;

            if(rand()%2){
                if(op[i][0]<0)op[i][0]=0;
                if(op[i][0]>=Nnum)op[i][0]=Nnum-1;
            }else{
                if(op[i][0]<0 || op[i][0]>=Nnum)op[i][0] += ch_x;
            }

            if(rand()%2){
                if(op[i][1]<0)op[i][1]=0;
                if(op[i][1]>=Nnum)op[i][1]=Nnum-1;
            }else{
                if(op[i][1]<0 || op[i][1]>=Nnum)op[i][0] += ch_y;
            }

            op[i][2] += ch_h;
            if(op[i][2] < 0)op[i][2]=0;
        }

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

        if(DBG){
            ifstream ifs("HC\\future2018q\\in.txt");
            rep(i,Nnum){
                rep(j,Nnum){
                    ifs>>a;
                    input[i][j]=a;
                }
            }
        }else{
            rep(i,Nnum){
                rep(j,Nnum){
                    cin>>a;
                    input[i][j]=a;
                }
            }
        }
        
        if(DBG)cout<<"input done"<<endl;
    }

    void solve(){
        solution.randomize();
        solution.eval();
        bestSOl = solution;

        Timer_start();
        priority_queue<ll,vector<ll>,greater<ll>> score;
        priority_queue< Sol,vector<Sol>,greater<Sol> > ranking_list;

        while (Timer_end() < 3000){
            if(DBG)cout<<"ms:"<<Timer_end()<<endl;
            ranking_list.push(solution);

            solution.randomize();
            solution.eval();
            if(solution.diff < bestSOl.diff){
                bestSOl = solution;
            }
            if(DBG)cout<<Timer_end()<<" , "<<ranking_list.size()<<endl;
        }

        int r=20,pass=5;
        priority_queue<Sol,vector<Sol>,greater<Sol>> top20,top20_buf;
        rep(i,20){
            top20.push(ranking_list.top());
            ranking_list.pop();
        }
        
        while(Timer_end() < 5500){
            rep(i,r){
                if(i < pass){
                    top20_buf.push(top20.top());
                    top20.pop();
                }else{
                    Sol tmp=(top20.top());
                    ll tmpdiff = tmp.diff;
                    tmp.change_little(3,2,1);

                    if(tmp.diff < tmpdiff)top20_buf.push(tmp);
                    top20_buf.push(top20.top());
                    top20.pop();
                }
            }

            top20 = top20_buf;
            while(!top20_buf.empty())top20_buf.pop();
        }


        if(!DBG)return;
        ofstream ofs_rank("HC\\future2018q\\top10.txt", ios::app);

        int ranking=20;
        rep(i,ranking){
            if(DBG)ofs_rank<<(top20.top()).diff;
            if(i+1!=ranking)if(DBG)ofs_rank<<",";
            top20.pop();
        }
        if(DBG)ofs_rank<<endl;

    }

    void out(){
        cout<<Pnum<<endl;
        rep(i,Pnum){
            int x=bestSOl.op[i][0];
            int y=bestSOl.op[i][1];
            int h=bestSOl.op[i][2];
            if(!DBG)cout<<x<<" "<<y<<" "<<h<<endl;
        }
    }
};



int main(){

    future2018q prob;
    
    prob.init();
    rep(i,1)prob.solve();
    prob.out();

    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
