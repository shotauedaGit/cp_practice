#include <bits/stdc++.h>
using namespace std;

#define INF 2147483647
#define LINF 9223372036854775807
#define MOD 1000000007
#define MOD2 998244353


// palameter
#define MX_LEN 40
#define REQ 10
#define RATIO -1
#define EXP_R (EXP_P_MX*(10-N)+EXP_P_MN*(N-6))/4

#define TREE_BREAK false

#define ITER_DUR 1

#define EXP_P_MX 3.0f
#define EXP_P_MN 1.0f

#define EXP_OFFSET 1.0f

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

bool isDBG=false;

int N,T;

ifstream input;
ofstream output;

std::random_device seed_gen;
std::mt19937 rnd(seed_gen());

string ds="LURD";

void show_v(vector<int> a,int n){
    if(!isDBG)return;

    rep(i,n*n){
        if(i%n==0)cout<<endl;
        cout << right << setw(3) << a[i];
    }
    cout<<endl;
}

void show_v(vector<char> a,int n){
    if(!isDBG)return;

    rep(i,n*n){
        if(i%n==0)cout<<endl;
        cout << right << setw(3) << a[i];
    }
    cout<<endl;
}

int toN(char c){
    int n;
    if('0' <= c && c <= '9'){
        n = (int)(c - '0');
    }else{
        n = (int)(c - 'a') + 10;
    }
    return n;
}

int L(int n){ if(n%N > 0)  return n-1; else return -1; }
int U(int n){ if(n/N > 0)  return n-N; else return -1; }
int R(int n){ if(n%N < N-1)return n+1; else return -1; }
int D(int n){ if(n/N < N-1)return n+N; else return -1; }

int Direc(int n,int d){
            switch (d){
                case 0: return L(n);
                case 1: return U(n);
                case 2: return R(n);
                case 3: return D(n);
                default: return -1;
            }
}

int Direc(int n,char c){
            switch (c){
                case 'L': return L(n);
                case 'U': return U(n);
                case 'R': return R(n);
                case 'D': return D(n);
                default: return -1;
            }
}


bool isL(int n){return (n%2 == 1);}
bool isU(int n){return ((n>>1)%2 == 1);}
bool isR(int n){return ((n>>2)%2 == 1);}
bool isD(int n){return ((n>>3)%2 == 1);}

bool isDirec(int n,int d){
            switch (d){
                case 0: return isL(n);
                case 1: return isU(n);
                case 2: return isR(n);
                case 3: return isD(n);
                default: return false;
            }
}


int tree_sz_cnt = 0;
int mv_gen_cnt = 0;
int iter = 0;

class puzzle{
    public:

    bool tree_sz_calced = false;
    int n;
    int p0;
    vector<int> tiles;
    vector<int> tree_sz;

    void Copy(puzzle p){
        n = p.n;
        p0 = p.p0;
        tiles = p.tiles;
        tree_sz_calced = p.tree_sz_calced;
        tree_sz = p.tree_sz;
    }

    void init(int _n,int _t){
        n = _n;

        tiles.resize(n*n,0);
        tree_sz.resize(n*n,0);

        rep(i,n*n){
            char c;

            if(isDBG)input>>c;
            else cin>>c;

            tiles[i] = toN(c);
            if(tiles[i] == 0){
                p0 = i;

            }
        }
    }

    string gen_move(int l){
        string ret;
        int p_d = -999,d,cur_p0 = p0;

        //cout<<"gen: "<<endl;
        while(l-- > 0){
            bool ok = false;
            while(!ok){
                d = rnd()%4;
                //db3(ds[d],cur_p0,Direc(cur_p0,d));ln;

                //さっきと逆は意味ない
                if(abs(p_d - d) == 2 ){
                    continue;
                }

                //行った先にマスがないのはダメ
                if(Direc(cur_p0,d) < 0)continue;

                //なるべく大きい木は崩したくない

                int r = RATIO;
                if(TREE_BREAK && tree_sz_calced){
                    if(tree_sz[Direc(cur_p0,d)]  >= (N*N)/2 && rnd()%100 > r)continue;
                }

                ok = true;
            }
            //cout<<cur_p0<<" ";

            ret += ds[d];
            cur_p0 = Direc(cur_p0,d);
            p_d = d;
            //db3(ds[d],cur_p0,Direc(cur_p0,ds[d]));ln;
            }
        //cout<<cur_p0<<" "<<endl;

        return ret;
    }

    
    void move(string mv){

        //cout<<"move: "<<mv<<endl;
        for(char d : mv){
            //cout<<p0<<" ";
            int nx_p0 = Direc(p0,d);
            
            //タイルのswap
            int temp = tiles[p0];
            tiles[p0] = tiles[nx_p0];
            tiles[nx_p0] = temp;
            
            //空白のいる場所更新
            p0 = nx_p0;
        }
        //cout<<p0<<endl;
        //動かしたのでツリーサイズは計算されていない
        tree_sz_calced = false;
    }

    void show_adj(){
        if(!isDBG)return;
        rep(i,N*N){
            if(i%N==0)cout<<endl;
            cout << right << setw(3) << tiles[i];
        }
    }

    vector<int> treesize(){
        vector<int> ret;
        return ret;
    }

    int treesize_DBG(bool show){

        int ret=-1;

        vector<bool> vis(N*N,false);

        vector<int> tree_id(N*N,-1);
        vector<bool> cyclic(N*N,false);

        int t_id=0;
        
        //cout<<"DFS"<<endl;
        rep(i,N*N){
            /*
            i番目のますが Lにつながっている 
            & L方向にますが存在する 
            & L方向のマスがRにつながっている
            */
            if(vis[i])continue;

            stack<int> st; st.push(i);
            while(!st.empty()){
                int cur = st.top(); st.pop();


                if(vis[cur]){
                    cyclic[t_id] = true;
                    break;
                }else{
                    vis[cur] = true;
                    //cout<<cur<<"("<<t_id<<")";
                    tree_id[cur] = t_id;
                }

                    if( isL(tiles[cur]) && L(cur) != -1 && isR(tiles[L(cur)]) ){ if(!vis[L(cur)])st.push(L(cur)); if(0)cout<<cur<<"->"<<L(cur)<<"("<<t_id<<")"<<endl; }
                    if( isU(tiles[cur]) && U(cur) != -1 && isD(tiles[U(cur)]) ){ if(!vis[U(cur)])st.push(U(cur)); if(0)cout<<cur<<"->"<<U(cur)<<"("<<t_id<<")"<<endl;}
                    if( isR(tiles[cur]) && R(cur) != -1 && isL(tiles[R(cur)]) ){ if(!vis[R(cur)])st.push(R(cur)); if(0)cout<<cur<<"->"<<R(cur)<<"("<<t_id<<")"<<endl;}
                    if( isD(tiles[cur]) && D(cur) != -1 && isU(tiles[D(cur)]) ){ if(!vis[D(cur)])st.push(D(cur)); if(0)cout<<cur<<"->"<<D(cur)<<"("<<t_id<<")"<<endl;}
            }

            ++t_id;
            //cout<<endl;
        }
        

        vector<int> tree_id_sz(t_id+1,0);

        rep(i,N*N){
            if(!cyclic[tree_id[i]])++tree_id_sz[tree_id[i]];
            else tree_id_sz[tree_id[i]] = -1;
        }
        // そいつが属する木は要素数いくつか？
        
        
        /*
        if(show)cout<<endl<<"current tree size"<<endl;
        rep(i,N*N){
            tree_sz[i] = tree_id_sz[tree_id[i]];
            if(show){
                if(i%N==0)cout<<endl;
                cout << right << setw(3) << tree_id_sz[tree_id[i]];
            }
        }
        if(show)cout<<endl;
        */


        sort(all(tree_id_sz),greater<int>());
        if(show)cout<<tree_id_sz[0]<<","<<tree_id_sz[1]<<","<<tree_id_sz[2]<<endl;

        tree_sz_calced = true;
        return tree_id_sz[0];
    }
};

class AHC011{
    public:
    string sub_temp;
    string submit;

    int end_score=-1;

    puzzle p;

    AHC011(puzzle _p){p.Copy(_p);}

    void main(double limit){
    pair<P,puzzle> best_score;
    string best_mv = "";
    
    best_score.first.first = iter;
    best_score.first.second = -1;
    best_score.second.Copy(p);


        while(Timer_end() < limit){
            //cerr<<"time:"<<Timer_end()<<" ms ";
            ++iter;
            
            puzzle temp_p;
            string temp_mv;

            //p.show_adj();
            int pv_sz = p.treesize_DBG(false); temp_p.Copy(p);
            int nw_sz = -1;
            bool ok = false;


            if(chmax(best_score.first.second,pv_sz)){
                best_score.second.Copy(p);
                best_score.first.first = iter;
                best_mv = submit;
            }

            if(pv_sz < best_score.first.second){
                if(best_score.first.first - iter >= ITER_DUR){
                    p.Copy(best_score.second);

                    pv_sz = p.treesize_DBG(false);
                    temp_p.Copy(p);
                    submit = best_mv;
                }
            }


            int req = REQ;

            /*
            if(iter <= 20)req = 20;
            else req = 2;
            */

            vector<pair<float,string>> c_perf;
            pair<float,string> implv;

            int cnt=0;

            ++tree_sz_cnt;
            while(cnt < req && Timer_end() < limit){
                temp_p.Copy(p);

                int len = (rnd()%MX_LEN + 4);

                //temp_p.treesize_DBG(false);
                temp_mv = temp_p.gen_move( len );
                temp_p.move( temp_mv );

                nw_sz = temp_p.treesize_DBG(false);

                tree_sz_cnt += 1;
                ++mv_gen_cnt;

                
                //悪いとダメ
                //if(nw_sz <= pv_sz)continue;
                
                //悪くても確率で採用
                float diff = pv_sz - nw_sz + EXP_OFFSET;
                //float diff = pv_sz - nw_sz;

                int r = (65536)*exp(-(diff*EXP_R));
                if((rnd()%65536) >= r)continue;

                implv.first =  diff/len;
                implv.second = temp_mv;

                //db2(implv.first*(-1) , implv.second);ln;
                c_perf.emplace_back(implv);
                cnt++;
                //cout<<temp_mv<<" : "<<pv_sz<<" -> "<<nw_sz<<endl;
            }

            
            if(cnt == 0)return;

            sort(all(c_perf));

            string best = c_perf[0].second;
            p.move(best);
            

            p.treesize_DBG(false);
            //p.show_adj();

            if(isDBG && (iter%10)==0){
                cerr<<"cur score "<<pv_sz<<" "<<Timer_end()<<" ms ";
                db3(tree_sz_cnt,mv_gen_cnt,iter);
                cout<<endl;

            }else if(iter%10==0){
                cerr<<"cur score "<<pv_sz<<" "<<Timer_end()<<" ms ";
                db3(tree_sz_cnt,mv_gen_cnt,iter);
                cerr<<endl;
            }

            if(submit.length() + best.length() <= T ){
                submit.append(best);
            }else{
                return;
            }

        }
    }

    void submit_mv(){
        end_score = p.treesize_DBG(false);

        if(isDBG)cout<<"submit: ";
        
        if(!isDBG){
            cout<<submit;
        }else{
            output<<(float)end_score/(N*N)<<endl;
        }
    }
};





int main(int argc, char *argv[]){

    Timer_start();

    if(argc > 1 && strcmp(argv[1],"114514") == 0){
        cout<<"it is DBG"<<endl;
        isDBG = true;
        input.open(argv[2],ios_base::in);
        output.open(argv[3],ios_base::app);
    }

    //isDBG = false;

    if(isDBG){
        cout<<"input"<<endl;
        input>>N>>T;
    }else{
        cin>>N>>T;
    }

    puzzle p;p.init(N,T);

    AHC011 prob(p);
    cerr<<"EXP_R"<<EXP_R<<endl;

    if(isDBG){
        prob.main(12000);
    }else{
        prob.main(2800);
    }
    prob.submit_mv();

    if(isDBG)cout<<"time:"<<Timer_end()<<endl;
    
    cerr<<"time:"<<Timer_end()<<endl;
    db3(tree_sz_cnt,mv_gen_cnt,iter);
    return 0;
}
