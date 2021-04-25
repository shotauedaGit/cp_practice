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

//bool DBG=false;
bool DBG=true;

int si,sj;

int t[50][50]={};
int p[50][50]={};

struct AHC002{
    char ans_out[50*50] = {};
    int sc_out=0;

    char ans_tmp[50*50] = {};
    int sc_tmp=-INF;
    int len_tmp=-1;

    char ans_sol[50*50] = {};

    void init(){
        if(!DBG){
            cin>>si>>sj;
            rep(i,50)rep(j,50){
                cin>>t[i][j];
            }
            rep(i,50)rep(j,50){
                cin>>p[i][j];
            }
        }else{
            ifstream input("AHC\\AHC002\\in.txt");
            input>>si>>sj;
            rep(i,50)rep(j,50){
                input>>t[i][j];
            }
            rep(i,50)rep(j,50){
                input>>p[i][j];
            }
        }

        
    }


    int solve(){
        Timer_start();

        int sc_out=0;
        int sc_tmp=-INF;
        int len_tmp=-1;

        int th = 5;
        char d[4] = {'R','D','L','U'};
        bool v[2500]={};
        int sol_try=0,imp=0;
        // R D L U;

        while(Timer_end() < 1919.810){
            set_as_tmp();
            ++sol_try;
            
            int sc_sol=0;
            int step=0;


            P cur(si,sj);
            rep(i,2500)v[i]=false;
            v[ t[si][sj] ] = true;

            if(sol_try >= 3000){
                int skip_step = rand()%len_tmp; 
                if(sol_try < 20000)skip_step = rand()%len_tmp;
                else skip_step = (len_tmp/2) + rand()%(len_tmp/2);
                
                step = skip_step;
                //途中まで進める
                rep(i,skip_step){
                    int idx = -1;
                    switch(ans_tmp[i]){
                        case 'L':idx=2; break;
                        case 'R':idx=0; break;
                        case 'U':idx=3; break;
                        case 'D':idx=1; break;
                        default: break;
                    }

                    //if(DBG && idx == -1)cout<<"!!!!"<<endl;

                    cur = P(cur.fi + dy[idx],cur.se + dx[idx]);
                    sc_sol += p[cur.fi][cur.se];
                    v[ t[cur.fi][cur.se] ] = true;
                }
            }
            
            //if(DBG)cout<<"[try:"<<sol_try<<endl;
            while(true){
                bool skip[4]={false,false,false,false};
                int pred[4]={-1,-1,-1,-1};

                bool islast=true;

                //if(cur.fi == 0 || cur.fi == 49 ||cur.se == 0 ||cur.se == 49){
                    rep(i,4){
                        int ni = cur.fi + dy[i];
                        int nj = cur.se + dx[i];
                        if(ni == -1 || ni == 50 || nj == -1 || nj == 50){
                            skip[i]=true;
                            continue;
                        }

                        if(v[ t[ni][nj] ] == false){
                            islast=false;
                            //pred[i] = p[ni][nj];
                        }else {skip[i]=true;}
                    }
                    if(islast == true){
                        break;
                    }
                //}
                


                int di,ni,nj;
                while(true){
                    di = rand()%4;
                    if(skip[di] == true)continue;

                    ni = cur.fi + dy[di];
                    nj = cur.se + dx[di];
                    int nt = t[ni][nj];

                    if(v[nt] == false){
                        v[nt]=true;
                        break;
                    }
                    else continue;
                }
                
                sc_sol += p[ni][nj];
                ans_sol[step] = d[di];
                cur = P(ni,nj);
                //if(DBG)cout<<"("<<ni<<","<<nj<<") ";


                ++step;
            }
            rep1(i,step,2500){
                ans_sol[i] = '\0';
            }

            //if(DBG)cout<<endl;


            if(sc_tmp < sc_sol){
                sc_tmp = sc_sol;
                len_tmp = step;
                rep(i,2500)ans_tmp[i] = ans_sol[i];
                ++imp;
                if(DBG){
                    //cout<<"imp: "<<imp<<" try: "<<sol_try<<" sc: "<<sc_sol<<endl;
                }

                /*
                ofstream output("AHC\\AHC002\\out_sol.txt");
                char c;
                rep(i,2500){
                    c = ans_sol[i];
                    if((c=='L' || c=='R' || c=='U' || c=='D'))output<<c;
                    else break;
                }
                */

            }else if(sc_tmp > sc_sol){
                
                //*
                if(sol_try < 3000)continue;
                
                double dm = (double)(sc_sol - sc_tmp);
                double T = ((1919.810-Timer_end())/1919.810)*(1000-1) + 1.0;

                double p = exp(dm/T);

                if( rand() < p*RAND_MAX ){

                    //if(DBG)cout<<"[passed] p: "<<p*100<<"% T: "<<T<<", "<<sc_tmp<<" -> "<<sc_sol<<endl;
                    sc_tmp = sc_sol;
                    len_tmp = step;
                    rep(i,2500)ans_tmp[i] = ans_sol[i];
                }
                //*/
            }
        }
        

        if(DBG){
            cout<<"#RES::  ";
            cout<<"imp: "<<imp<<" try: "<<sol_try<<" sc: "<<sc_tmp<<endl;
        }
        rep(i,2500)ans_out[i] = ans_tmp[i];
        return sc_tmp;
    }

    void out(){
        if(DBG){
            ofstream output("AHC\\AHC002\\out.txt");
            char c;
            rep(i,2500){
                c = ans_out[i];
                if((c=='L' || c=='R' || c=='U' || c=='D'))output<<c;
                else break;
            }

        }else{
            char c;
            rep(i,2500){
                c = ans_out[i];
                if((c=='L' || c=='R' || c=='U' || c=='D'))cout<<c;
                else break;
            }
        }
    }

    void reset(){
        rep(i,2500)ans_sol[i] = '\0';
    }

    void set_as_tmp(){
        rep(i,2500)ans_sol[i] = ans_tmp[i];
    }
};


int main(){

    srand(time(NULL));
    AHC002 pb;

    int reps;
    if(DBG)reps=1;
    else reps=1;

    double sum=0;
    pb.init();
    rep(i,reps)sum+=pb.solve();
    
    pb.out();
    if(DBG)cout<<"    [ave]:: "<<sum/reps<<endl;

    //cout <<fixed<<setprecision(16)<< << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
