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

int dx[4]={1,-1,-1,1};
int dy[4]={-1,-1,1,1};

int g[100][100]={};

    bool is_out(int x,int y){
        if(!(0<=x&&x<Nnum && 0<=y&&y<Nnum))return true;
        return false;
    }

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int n=100;
    srand(time(NULL));


    string out_file = "HC\\future2018q\\in_answer.txt";
    ofstream write_file_1;
    write_file_1.open(out_file, std::ios::out);

    write_file_1<<1000<<endl;

    rep(i,1000){
        int x,y,h;
        x = rand()%n;
        y = rand()%n;
        h = rand()%n + 1;

        write_file_1<<x<<" "<<y<<" "<<h<<endl;

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






    string filename = "HC\\future2018q\\in.txt";
    ofstream write_file;
    write_file.open(filename, std::ios::out);

        rep(i,Nnum){
            rep(j,Nnum){
                write_file<<g[j][i]<<" ";
            }
            write_file<<endl;
        }

    cout<<"done"<<endl;
    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
