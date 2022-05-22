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

chrono::system_clock::time_point  start;
void Timer_start(){start = std::chrono::system_clock::now();}
double Timer_end(){
    auto end = std::chrono::system_clock::now();
    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count(); //処理に要した時間をミリ秒に変換
    return elapsed;
}

//引用元
//https://qiita.com/iseki-masaya/items/70b4ee6e0877d12dafa8

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
    if (!item.empty()) {
            elems.push_back(item);
        }
    }
    return elems;
}




enum cell_type{
    nothing=-1,  //通過可能
    nearpets=0, //ペットの周囲は障害物置けない
    cow,
    pig,
    rabbit,
    dog,
    cat,
    person,   //人
    obstacle  //通過不可能
};

struct entity{
    /*
    0:nothing 1:cow 2:pig 3:rabbit 4:dog 5:cat  99:can't pass(優先度高) -1:can't select(優先度低) [10:preson]
    */
    int x=0,y=0;
    cell_type type;
};

#define A 30

class AHC008{
    std::random_device rnd_dvc;
    std::mt19937 mt;

    public:
    ifstream in_file;
    ofstream out_file,score_list;
    bool isDBG = false;

    ll score=0;
    int loopcnt=0;

    int N,M;

    //
    cell_type p[A][A]; // room width

    vector<entity> emp; // size:M
    vector<entity> pets; // size:N

    unordered_map<char,int> dx;
    unordered_map<char,int> dy;
    string d4="RDLU";

    AHC008(){
        cerr<<"constructor"<<endl;
            {
                dx['U'] = -1; dx['u'] = -1;
                dx['D'] = 1; dx['d'] = 1;
                dx['L'] = 0; dx['l'] = 0;
                dx['R'] = 0; dx['r'] = 0;

                dx['.'] = 0;

                dy['U'] = 0; dy['u'] = 0;
                dy['D'] = 0; dy['d'] = 0;
                dy['L'] = -1; dy['l'] = -1;
                dy['R'] = 1; dy['r'] = 1;

                dy['.'] = 0;
            }

        mt = mt19937(rnd_dvc());
        rep(i,A)rep(j,A)p[i][j]=nothing;

        //***     ***//
        cin>>N;pets.resize(N);
        rep(i,N){
            int xi,yi,ti;
            cin>>xi>>yi>>ti;--xi;--yi;

            cell_type pet_type = static_cast<cell_type>(ti);
            pets[i].x = xi; pets[i].y = yi; pets[i].type = pet_type;

            p[xi][yi] = pet_type;
            rep(i,4){
                char di = d4[i];
                int nx = xi+dx[di];
                int ny = yi+dy[di];

                if(isIn(nx,ny) && p[nx][ny] == nothing){
                    p[nx][ny] = nearpets;
                }
            }

        }

        cin>>M; emp.resize(M);
        rep(i,M){
            int xi,yi;
            cin>>xi>>yi;--xi;--yi;
            emp[i].x = xi; emp[i].y = yi;
            
            p[xi][yi] = person;
        }

        cerr<<"constructor end"<<endl;
    }

    inline bool isIn(int x,int y){
        return (0<=x && x<A)&&(0<=y && y<A);
    }

    void init(){
        isDBG = false;
    }
    void init(char *_seed,char *_comment){
        isDBG = true;
        int seed = atoi(_seed);

        string score_file_name = _comment; score_file_name += ".txt";
        score_list.open("scores\\"+ score_file_name,ios_base::app);

        /*
        string in_file_name = to_string(10000+seed).substr(1,4) + ".txt";
        string out_file_name = to_string(10000+seed).substr(1,4) + ".txt";
        in_file.open("in\\" + in_file_name);
        out_file.open("out\\" + out_file_name);
        */
    }


    void mvPerson(){
        cerr<<"mv person begin"<<endl;

        vector<char> outputOP(M);
        string rnd = "UDLRudlr.";
        string ordr = "urdl.";
        
        rep(i,M){
            char op;
            /*
            while(true){
                op = rnd[mt()%4];
                if(isIn(emp[i].x + dx[op],emp[i].y + dy[op]))break;
            }
            outputOP[i] = op;
            cerr<<"loop: "<<loopcnt<<","<<i<<" th end"<<endl;
            */

            if(emp[i].x == 0 ||emp[i].x == 29 ||emp[i].y == 0 || emp[i].y == 29){
                while(true){
                    op = rnd[mt()%4];
                    if(isIn(emp[i].x + dx[op],emp[i].y + dy[op]))break;
                }
            }else{
                op = ordr[loopcnt%4];
                if(    p[emp[i].x + dx[op]][emp[i].y + dy[op]] != nothing ){
                    op = '.';
                }else{
                    p[emp[i].x + dx[op]][emp[i].y + dy[op]] = obstacle;
                }
            }

            outputOP[i] = op;
        }



    //***out put move***//
        string outstr = "";
        for(char op:outputOP)outstr+=op;
        cout<<outstr<<endl<<flush;

        cerr<<"output end"<<endl;

    //*** 盤面・配列更新
        rep(i,M){
            char op = outputOP[i];

            if(islower(op))continue;
            
            int xi = emp[i].x;
            int yi = emp[i].y;

            emp[i].x = xi + dx[op]; emp[i].y = yi + dy[op];

            p[xi][yi] = nothing;
            p[xi + dx[op]][yi + dy[op]] = person;
        }
    }


    void mvPets(){
        cerr<<"mv pets begin"<<endl;
        //***in put move***//
        string instr;
        vector<string> mv(N);
        rep(i,N)cin>>mv[i];
        cerr<<"pets input"<<endl;
        //mv = split(instr,' ');
        
        for(string s:mv){
            cerr<<s<<" ";
        }
        cerr<<endl;

        //*****************//

        //*** update pets
        cerr<<"updating..."<<endl;
        rep(i,N){
            for(char op:mv[i]){
                cerr<<op;

                int xi = pets[i].x;
                int yi = pets[i].y;

                
                cell_type pet_type = p[xi][yi];
                p[xi][yi] = nothing;

                rep(i,4){
                    char di = d4[i];
                    if(isIn(xi+dx[di],yi+dy[di]) && p[xi+dx[di]][yi+dy[di]]==nearpets){
                        p[xi+dx[di]][yi+dy[di]]=nothing;
                    }
                }

                pets[i].x = xi + dx[op]; pets[i].y = yi + dy[op];
                xi = pets[i].x;
                yi = pets[i].y;
                p[xi][yi] = pet_type;

                rep(i,4){
                    char di = d4[i];
                    if(isIn(xi+dx[di],yi+dy[di]) && p[xi+dx[di]][yi+dy[di]]==nothing){
                        p[xi+dx[di]][yi+dy[di]]=nearpets;
                    }
                }
            }
            cerr<<" ";
        }
    }

    void mainLoop(){
        cerr<<"mainLoop"<<endl;

        rep(i,300){
            cerr<<"Loop "<<loopcnt<<endl;
            mvPerson();
            mvPets();
            ++loopcnt;
        }

        if(isDBG)score_export();
    }

    void score_export(){
        
    }
};


int main(int argc, char *argv[]){
    bool flag=false;
    ll ans=0,sum=0;


    
    AHC008 q;
    if(argc==4 && strcmp(argv[3],"ak9_local_test")==0){
        q.init(argv[1],argv[2]);
    }else{
        q.init();
    }
    
    q.mainLoop();



    //cout << argc <<" "<<argv[1]<<" "<<argv[2]<<endl;
    return 0;
}
