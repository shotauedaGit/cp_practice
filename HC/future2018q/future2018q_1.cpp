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

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}

int dx[4]={1,-1,-1,1};
int dy[4]={-1,-1,1,1};

int dx8[8] ={1,1,0,-1,-1,-1, 0, 1};
int dy8[8] ={0,1,1, 1, 0,-1,-1,-1};

chrono::system_clock::time_point  start;
void Timer_start(){start = std::chrono::system_clock::now();}
double Timer_end(){
    auto end = std::chrono::system_clock::now();
    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count(); //処理に要した時間をミリ秒に変換
    return elapsed;
}

#define N 100
#define P 1000

bool DBG=true;
//bool DBG=false;
int input[N][N]={};

struct Sol{
    ll diff=-1;
    int op[P][3];
    int diff_i[P];//useless;
    int g[N][N];

    void copy(const Sol &src){
        diff = src.diff;
        rep(i,P){
            op[i][0] = src.op[i][0];
            op[i][1] = src.op[i][1];
            op[i][2] = src.op[i][2];
        }
        rep(i,N){rep(j,N)g[i][j] = src.g[i][j];}
    }
    Sol &operator=(const Sol &src){copy(src); return (*this);}

    void init(){
        rep(i,P){
            op[i][0] = rand()%N;
            op[i][1] = rand()%N;
            op[i][2] = (rand()%N)+1;
            make_m(op[i][0],op[i][1],op[i][2]);
        }

        diff=0;
        rep(i,N){rep(j,N){
            g[i][j]-=input[i][j];
            diff+=labs(g[i][j]);
        }}
    }

    bool is_out(int x,int y){
        if(!(0<=x&&x<N && 0<=y&&y<N))return true;
        return false;
    }

    void make_m(int x,int y,int h){
            int abs_h=abs(h);
            g[x][y]+=h;

            for(int j=1;j<abs_h;j++){
                int cx = x;
                int cy = y + j;
                rep(di,4){
                    rep(k,j){ 
                        cx += dx[di];cy += dy[di];
                        if(is_out(cx,cy)==false){
                            if(h>0)g[cx][cy] += h-j;
                            else g[cx][cy] += h+j;
                        }
                    }
                }
            }
    }
    ll eval_one(int x,int y,int h){
        ll ret=0;
        int abs_h=abs(h);
        ret = labs(g[x][y]);

            for(int j=1;j<abs_h;j++){
                int cx = x;
                int cy = y + j;
                rep(di,4){
                    rep(k,j){ 
                        cx += dx[di];cy += dy[di];
                        if(is_out(cx,cy)==false){
                            ret += labs(g[cx][cy]);
                        }
                    }
                }
            }
        return ret;
    }
    ll eval_all(){
        ll ret=0;
        rep(i,N){
            rep(j,N){
            ret += abs(g[i][j]);
            }
        }
        return ret;
    }

    void modfy_one(int i,int try_limit,int pos_range=999,int h_range=999){
        int min_h = max(1,op[i][2]-h_range);
        int max_h = min(N,op[i][2]+h_range);

        int min_y = max(0,op[i][1]-pos_range);
        int max_y = min(N-1,op[i][1]+pos_range);

        int min_x = max(0,op[i][0]-pos_range);
        int max_x = min(N-1,op[i][0]+pos_range);

        rep(iter,try_limit){
            int new_h = rand()%(max_h - min_h + 1) + min_h;
            int new_x = rand()%(max_x - min_x + 1) + min_x;
            int new_y = rand()%(max_y - min_y + 1) + min_y;
            
            //int old_diff_i = eval_one(op[i][0],op[i][1],new_h);
            ll old_diff_i = eval_all();

            make_m(op[i][0],op[i][1], -op[i][2]);
            make_m(new_x,new_y, new_h);

            //int new_diff_i = eval_one(op[i][0],op[i][1],new_h);
            ll new_diff_i = eval_all();

            if(new_diff_i < old_diff_i){
                if(DBG){
                    //cout<<"("<<op[i][0]<<","<<op[i][1]<<","<<op[i][2]<<")"<<
                //" -> "<<"("<<new_x<<","<<new_y<<","<<new_h<<")"<<endl;
                }
                op[i][0] = new_x;op[i][1] = new_y;op[i][2] = new_h;
                diff = new_diff_i;

                return ;
            }else{
                make_m(new_x,new_y, -new_h);
                make_m(op[i][0],op[i][1], op[i][2]);
            }
            
        }

    }
};

struct future2018q{
    Sol s1,bestSol;
    vector<ll> diff_array;
    int a[15]={100,80,65,49,37,26,15,9,5,3,2,1   ,1,1,1};
    int loop=0;

    void init(){
        Timer_start();
        if(DBG){
            ifstream in("HC\\future2018q\\example_01.txt");
            rep(i,N)rep(j,N)in>>input[j][i];
        }else{
            rep(i,N)rep(j,N)cin>>input[j][i];
        }
        s1.init();
    }

    void solve(){
        
        int start_solve = Timer_end();
        while(Timer_end() < 5800){
            ++loop;
            int i = rand()%P;

            int idx = (Timer_end() - start_solve)/500;
            s1.modfy_one(i,1,a[idx],a[idx]);

            if(DBG){
                //cout<<loop<<" times "<<s1.diff<<endl;
                diff_array.emplace_back(s1.diff);
            }
        }
        bestSol = s1;
    }

    void out(){
        //cout<<loop<< " score : "<< (200000000 - bestSol.diff) <<endl;
        cout<<P<<'\n';
        if(!DBG){
            rep(i,P){
                cout<<bestSol.op[i][0]<<" "
                    <<bestSol.op[i][1]<<" "
                    <<bestSol.op[i][2]<<'\n';
            }
        }else{
            ofstream output("HC\\future2018q\\out.txt");
            cout<<loop<< " score : "<< bestSol.diff <<endl;
            output<<P<<'\n';
            rep(i,P){
                output<<bestSol.op[i][0]<<" "
                    <<bestSol.op[i][1]<<" "
                    <<bestSol.op[i][2]<<'\n';}
            output<<endl;
        }
    }

};

int main(){
    srand(time(NULL));

    future2018q prob;
    prob.init();
    prob.solve();
    prob.out();

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;

}
