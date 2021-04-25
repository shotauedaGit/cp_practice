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

const int W = 10000;
int N;
bool DBG=true;
//bool DBG=false;

struct Ad{
    int xi,yi,x1,y1,x2,y2;
    int r,s;
    double p;

    void init(int _xi,int _yi,int _r){
        r=_r;xi=_xi;yi=_yi;
        
        x1=xi;
        y1=yi;
        x2=xi+1;
        y2=yi+1;
    }

    void Copy(const Ad &src){
        xi=src.xi;
        yi=src.yi;
        x1=src.x1;
        y1=src.y1;
        x2=src.x2;
        y2=src.y2;
        r=src.r;p=src.p;s=src.s;
    }
    Ad& operator=(const Ad &src){Copy(src);return *this;}

    int calc_S(int x1,int y1,int x2,int y2){return abs(x2-x1)*abs(y2-y1);}
    double calc_P(int x1,int y1,int x2,int y2){
        int si = calc_S(x1,y1,x2,y2);
        double ret;double tmp = 1.0-(double)min(r,si)/max(r,si);
        ret = 1-tmp*tmp;
        return ret;
    }
    double calc_P(){
        int si = calc_S(x1,y1,x2,y2);
        double ret;double tmp = 1.0-(double)min(r,si)/max(r,si);
        ret = 1-tmp*tmp;
        return ret;
    }

    bool is_on(){
        bool f1=false,f2=false,f3=false,f4=false;
        if(0<= x1 && x1<= W)f1=true;
        if(0<= x2 && x2<= W)f2=true;
        if(0<= y1 && y1<= W)f3=true;
        if(0<= y2 && y2<= W)f4=true;
        return f1&&f2&&f3&&f4;
    }
    bool contains_point(){
        bool f1=false,f2=false;
        if(x1<= xi && xi<=x2)f1=true;
        if(y1<= yi && yi<=y2)f2=true;
        return f1&&f2;
    }
    bool trsf(int mode,int d){
        bool formed = false;
        switch (mode){
        case 1:
            y1 -= d;
            if(0<= y1  && y1 <= W){formed = true;}
            else y1 += d;
            break;

        case 2:
            x2 += d;
            if(0<= x2  && x2 <= W){formed = true;}
            else x2 -= d;
            break;
        
        case 3:
            y2 += d;
            if(0<= y2 &&  y2 <= W){formed = true;}
            else y2 -= d;
            break;

        case 4:
            x1 -= d;
            if(0<= x1 && x1 <= W){formed = true;}
            else x1 += d;
            break;
        
        default:
            break;
        }
        return formed;
    }
    bool move(int mode,int d){
        bool formed;
        switch (mode){
        case 1:
            y1 -= d; y2-=d;
            if(0<= y1  && y1 <= W){formed = true;}
            else y1 += d;y2 += d;
            break;

        case 2:
            x2 += d; x1 += d;
            if(0<= x2  && x2 <= W){formed = true;}
            else x2 -= d;x1 -= d;
            break;
        
        case 3:
            y2 += d; y1 += d;
            if(0<= y2 &&  y2 <= W){formed = true;}
            else y2 -= d; y1 -= d;
            break;

        case 4:
            x1 -= d;x2 -= d;
            if(0<= x1 && x1 <= W){formed = true;}
            else x1 += d;x2 += d;
            break;
        
        default:
            break;
        }

        return formed;
    }

};

struct AHC001{

    vector<Ad> Ads;
    vector<double> p_vec;
    int loop=0,improved=0;
    int score_down=0;

    bool conj(Ad &a,Ad &b){

        bool fx = !((b.x2 <= a.x1)||(a.x2 <= b.x1 ));
        bool fy = !((b.y2 <= a.y1)||(a.y2 <= b.y1 ));

        return fx&&fy;
    }

    void init(){
        int Xi,Yi,Ri;
        
        if(DBG){
            ifstream input("AHC\\AHC001\\in.txt");
            input>>N;
            Ads.resize(N);p_vec.resize(N);
            rep(i,N){
                input>>Xi>>Yi>>Ri;
                Ads[i].init(Xi,Yi,Ri);
                p_vec[i] = Ads[i].calc_P();
            }
        }else{
            cin>>N;
            Ads.resize(N);p_vec.resize(N);
            rep(i,N){
                cin>>Xi>>Yi>>Ri;
                Ads[i].init(Xi,Yi,Ri);
                p_vec[i] = Ads[i].calc_P();
            }
        }

        Timer_start();
    }

    int d(int cur_time){
        //float r = ((4800.0-cur_time)/cur_time)*10;
        //return max((int)r,1);
        return 1;
    }

    float T(int cur_time){
        float c = 0.0001;
        float p = c*((4800.0-cur_time)/4800.0);
        if(cur_time < 1000){
            return 0;
        }else{
            return p;
        }
    }

    void solve(){
        if(DBG)cout<<"solve begin"<<'\n';

        while(Timer_end() < 4800){

            ++loop;
            if(loop%(3000000/10) == 0 && (DBG)){
                cout<<"time: "<<Timer_end()
                <<" imp: "<<improved
                <<" down: "<<score_down;
                double score=0;
                rep(i,N)score+=p_vec[i];
                cout<<" sc : "<< score/N <<endl;
            }

            int target = rand()%N;
            int mode0 = rand()%2;
            //int mode0 = 0;
            int mode = (rand()%4) + 1;
            int delta = d(Timer_end());

            double old_P,new_P;
            old_P = Ads[target].calc_P();
            bool formed=false;

            if(mode0==0)formed = Ads[target].trsf(mode,delta);
            else formed = Ads[target].move(mode,delta);

            if(!formed)continue;

            bool conjunction = false;
            rep(i,N){
                if(i == target)continue;
                if(conj(Ads[i],Ads[target])){
                    conjunction=true;
                    break;
                }
            }
            if(conjunction){
                Ads[target].trsf(mode,-delta);
                continue;
            }

            new_P = Ads[target].calc_P();

            if(Ads[target].contains_point() == false){
                    if(mode0==0)Ads[target].trsf(mode,-delta);
                    else Ads[target].move(mode,-delta);

            }else if(new_P > old_P){
                p_vec[target] = new_P;
                improved++;
            }else{
                if(T(Timer_end())*32767.0 > rand() ){
                    p_vec[target] = new_P;
                    score_down++;
                }else{
                    if(mode0==0)Ads[target].trsf(mode,-delta);
                    else Ads[target].move(mode,-delta);
                }
            }
            
        }

        if(DBG){

            cout<<"solve end"<<endl;
            cout<<"loop: "<<loop
            <<" inproved: "<<improved;
            double score=0;
            rep(i,N)score+=p_vec[i];
            cout<<" score : "<< score/N <<endl;
        }
    }

    void out(){
        if(!DBG){
            rep(i,N){
                cout<<Ads[i].x1<<" "
                <<Ads[i].y1<<" "
                <<Ads[i].x2<<" "
                <<Ads[i].y2;

                if(i < N-1)cout<<'\n';
            }
        }else{
            ofstream output("AHC\\AHC001\\out.txt");
            //output<<N<<'\n';
            rep(i,N){
                output<<Ads[i].x1<<" "
                <<Ads[i].y1<<" "
                <<Ads[i].x2<<" "
                <<Ads[i].y2<<'\n';
            }
        }
    }
};





int main(){

    bool flag=false;
    ll ans=0,sum=0;

    srand(time(NULL));
    AHC001 prob;
    prob.init();
    prob.solve();
    prob.out();

    //cout <<fixed<<setprecision(16)<< << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
