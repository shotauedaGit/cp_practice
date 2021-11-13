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

#define N 1000
#define M 20
#define D 2000

#define isDBG true
#define pred false
#define errPrint false


class HTTF2022Q{

    public:
    int rd_change = 0,implv=0,failed=0;

    int K,R;
    int today=0;
    
    int task_done_cnt=0;
    vector< P > task_dt;

    int task_doing[M];

    vector< vector<float> > d;
    vector< vector<float> > s;

    vector<vector<int>> adj;

    // iさんがtask[j]にwij日かかった履歴
    vector<vector<P>> past_task;

    ofstream outputfile,outputscorefile;

    HTTF2022Q(int k,int r){
        
        if(isDBG)outputfile.open("C:\\prog\\gitrepos\\cp_practice\\AHC\\HTTF2022Q\\tools\\out.txt",std::ios::out);
        if(isDBG)outputscorefile.open("C:\\prog\\gitrepos\\cp_practice\\AHC\\HTTF2022Q\\tools\\score.txt",std::ios::app);

        // init
        K=k;R=r;

        // tasks
        d.resize(N);

        // member
        float ex = sqrtf(2.0/(atan(1.0)*4.0*K))*30.0;
        //float ex = 0.0f;

        s.resize(M);
        rep(i,M)s[i] = vector<float>(K,ex);


        past_task.resize(M);


        // doing
        fill_n(task_doing,M,-1);

        // task begin end
        task_dt.resize(N);
        fill(all(task_dt),P(0,0));

        // task adj list
        // 先にやっておかないといけないlist
        adj.resize(N);

        rep(i,N){
            vector<float> di(k,0.0f);
            rep(j,k){cin>>di[j];}
            d[i] = di;
        }

        rep(i,r){
            int vi,ui; cin>>ui>>vi; --vi;--ui;
            adj[vi].emplace_back(ui);
        }
    }

    vector<int> doable_task(){
        
        vector<int> ret;
        rep(i,N){
            bool isdoable = true;
            if(task_dt[i].second != 0 || task_dt[i].first != 0)continue;

            for(int ti : adj[i]){
                if(task_dt[ti].second == 0){isdoable = false; break;}
            }
            if(isdoable)ret.emplace_back(i);
        }

        /*
        //cerr<<"day:"<<today<<" doable: "<<ret.size()<<endl;
        cerr<<"day "<<today<<": ";
        if(ret.size() > M){
            cerr<<"******* 20+ ********"<<endl;
        }else{
            rep( i , (int)ret.size())cerr<<"*";
            cerr<<endl;
        }
        */

        return ret;
    }
    float skill_func(vector<float> di,vector<float> si){
        float ret=1.0;
        rep(i,K){
            ret += max( 0.0f ,di[i]-si[i]);
        }
        return ret;
    }

    void change_si_random(int si){
        double now = Timer_end();

        int rnd_k = rand()%K;

        //int rd_change_cur = rd_change;
        while(/*(Timer_end()-now) < 1.0*/ Timer_end()<(2.7f*task_done_cnt)+80){
            rnd_k = rand()%K;
            
            int r1 = -1,r2 = -1;
            int r = (rand()%100);

            if(past_task[si].size() <= 3){

                if(r >= r1)change_skill(si,rnd_k, 0.5f ,true);
                else change_skill(si,rnd_k, -0.1f ,true);

            }else{
            
                if(r >= r2)change_skill(si,rnd_k, 0.5f ,true);
                else change_skill(si,rnd_k, -0.5f ,true);
            } 
        }
    }
    void change_skill(int si,int k,float dx,bool isFirst){
        vector<float> si_1 = s[si];
        // modify
        si_1[k] += dx; chmax(si_1[k],0.0f); chmin(si_1[k],60.0f);

        float St=0.0f,St_1=0.0f;

        for(P p : past_task[si]){
            int tsk = p.first;
            float T_tsk = p.second;
            float t_tsk = 1.0f,t1_tsk = 1.0f;

            rep(i,K){
                t_tsk += max(0.0f , d[tsk][i] - s[si][i]);
                t1_tsk += max(0.0f , d[tsk][i] - si_1[i]);
            }

            St   += (T_tsk - t_tsk)*(T_tsk - t_tsk);
            St_1 += (T_tsk - t1_tsk)*(T_tsk - t1_tsk);
        }

        int time_left = (3000-(int)Timer_end());
        int rnd = rand()%1000;

        ++rd_change;
        if(St_1 < St){
            // modify
            s[si][k] += dx; chmax(s[si][k],0.0f); chmin(s[si][k],60.0f);
            ++implv;
            change_skill(si,k,dx,isFirst);

        }else if(St_1 > St){
            if(isFirst){
                change_skill(si,k,-dx,false);
            }
            ++failed;
        }else if(St_1 == St && ((time_left/120)+1) > rnd && false){
            // modify
            s[si][k] += dx; chmax(s[si][k],0.0f); chmin(s[si][k],60.0f);
            ++implv;
            if(dx >= 0.1f)change_skill(si,k,dx,isFirst);
        }
    }
    void change_si(int si,int task,int took){
        float r;
        int done = past_task[si].size()+1;
        

        if(past_task[si].size() == 0){
            r = 1.0f/(sqrt(took/7));
        }else{
            r = 1.0f/(sqrt(done)*(sqrt(took/7)));
        }

        if(r>1.0f)r=1.0f;

        rep(i,K){
            s[si][i] = (1-r)*s[si][i] + r*(5.0f/2.0f)*d[task][i];
            chmax(s[si][i],0.0f);
        }
    }
    bool addDate(){

        ++today;
        vector<int> done_member;
        vector<int> done_task;

        if(today != 1){
            int mi; cin>>mi;
            //cerr<<fixed<<setprecision(3)<<Timer_end()<<endl;

            if(mi == -1){
                int score,cnt=0;
                rep(i,N)if(task_dt[i].second != 0)cnt++;

                score = (D - min(today-1,D)) + cnt;
                cerr<<"score_self:"<<score<<endl;
                outputscorefile<<score<<endl;

                cerr<<rd_change<<","<<implv<<","<<failed<<endl;
                cerr<<Timer_end()<<endl;
                return true;
            }
            
            if(errPrint)cerr<<mi<<" has done task:";
            rep(i,mi){
                int si;
                cin>>si;--si;
                if(errPrint)cerr<<", ["<<si+1<<","<<task_doing[si]+1<<"]";
                done_task.emplace_back( task_doing[si] );
                //cerr<<"1 ";

                int day_took = today - task_dt[ task_doing[si] ].first;
                //cerr<<"2 ";
                task_dt[ task_doing[si] ].second = today;
                //cerr<<"3 ";
                past_task[si].emplace_back(P(task_doing[si] , day_took));
                //cerr<<"4 ";
                // void.
                //change_si(si,task_doing[si],day_took);

                ++task_done_cnt;
                //if(task_done_cnt == 1 ||task_done_cnt%100 == 0)cerr<<task_done_cnt<<": "<<Timer_end()<<" ms"<<endl;
                change_si_random(si);

                //cerr<<rd_change<<","<<implv<<","<<failed<<endl;
                //cerr<<"5 ";

                
                if(pred && si == 0){
                    cout<<"#s "<<si+1;
                    cerr<<"#s "<<si+1;
                    outputfile<<"#s "<<si+1;

                    
                    rep(j,K){
                        outputfile<<fixed<<setprecision(0)<<" "<<s[si][j];
                        cerr<<fixed<<setprecision(0)<<" "<<s[si][j];
                        cout<<fixed<<setprecision(0)<<" "<<s[si][j];
                    }
                    outputfile<<endl;
                    cerr<<endl;
                    cout<<endl;
                }

                task_doing[si] = -1;
                //cerr<<"6 ";
            }
            
            if(errPrint)cerr<<endl;

        }else{
            rep(si,M){
                if(pred){
                        cout<<"#s "<<si+1;
                        //cerr<<"#s "<<si+1;
                        outputfile<<"#s "<<si+1;

                        
                        rep(j,K){
                            outputfile<<fixed<<setprecision(0)<<" "<<s[si][j];
                            //cerr<<fixed<<setprecision(0)<<" "<<s[si][j];
                            cout<<fixed<<setprecision(0)<<" "<<s[si][j];
                        }
                        outputfile<<endl;
                        //cerr<<endl;
                        cout<<endl;
                }
            }
        }

        //doable task
        int member_cnt=0;
        vector<P> output;

        //誰が何やるか決める
        /**/
        vector<int> doable_tasks = doable_task();
        //　人/タスク の touple
        vector<pair<float,P>> skill_error;

        int pat=0;
        for(int ti : doable_tasks){
            rep(i,M){
                if(task_doing[i] != -1)continue;
                pair<float,P> p = make_pair(skill_func(d[ti],s[i]),P(i,ti));
                skill_error.emplace_back(p);

                pat++;
                //cerr<<pat<<": score "<<p.first<<"(m,t)= "<<i<<","<<ti<<endl;
            }
        }

        unordered_map<int,int> task_member;
        
        bool ismemberdoable[M];
        rep(i,M)ismemberdoable[i]=true;

        sort(all(skill_error));

        for(pair<float,P> p : skill_error){
            if(!ismemberdoable[p.second.first])continue;
            if(task_member.find(p.second.second) == task_member.end()){
                task_member[p.second.second] = p.second.first;
                ismemberdoable[p.second.first] = false;
            }
        }

        for(pair<int,int> p:task_member){
            output.emplace_back(P(p.second,p.first));
        }

        /**/
        //print

        if(isDBG){
            outputfile<<output.size()<<" ";
            cout<<output.size()<<" ";
            if(errPrint)cerr<<output.size()<<" works today!";
        }
        else cout<<output.size()<<" ";
        //cerr<<"output?"<<endl;
        
        for(P pi:output){
            if(isDBG){
                outputfile<<pi.fi + 1<<" "<<pi.se + 1<<" ";
                if(errPrint)cerr<<pi.fi + 1<<" "<<pi.se + 1<<" ";
                cout<<pi.fi + 1<<" "<<pi.se + 1<<" ";
            }
            else cout<<pi.fi + 1<<" "<<pi.se + 1<<" ";

            task_doing[pi.fi] = pi.se;
            task_dt[pi.se].first = today;
        }
        
        if(isDBG){
            outputfile<<endl;//<<flush;
            cout<<endl<<flush;
            if(errPrint)cerr<<endl<<flush;

        }else cout<<flush;

        return false;
    }
};

int main(){

    Timer_start();
    srand(time(NULL));
    int _n,_m,_k,_r;
    cin>>_n>>_m>>_k>>_r;

    HTTF2022Q a(_k,_r);
    while(a.addDate() == false){
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    return 0;
}
