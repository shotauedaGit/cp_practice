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

pair<int , float> file_open(unsigned int id){
    int skill_sum = 0;
    string filename = "0000";
    rep(i,4){
        filename[3-i] = (char)(filename[3-i] + (id%10));
        id/=10;
    }
    string path = "in\\";
    string suc = ".txt";
    path.append(filename);
    path.append(suc);

    ifstream tgt_file(path);
    //cout<<path;
    int N,M,K,R;
    tgt_file>>N>>M>>K>>R;

    int p;
    rep(i,K)tgt_file>>p;
    rep(i,2)tgt_file>>p;

    int mx_skill_sum_i = INF;
    float mx_skill_avg_i = 999.9f;
    //float mx_skill_avg_i = -1.0f;
    int num=0;
    rep(i,M){
        int skill_sum_i = 0;
        float skill_avg_i = 0;
        rep(j,K){
            tgt_file>>p;
            //cout<<p<<" ";

            skill_sum += p;
            skill_sum_i += p;
            skill_avg_i += p;
        }
        skill_avg_i /= K;
        if(chmin(mx_skill_avg_i,skill_avg_i)){
            num = i+1;
        }
        //cout<<endl;
    }
    tgt_file.close();
    //return skill_sum;
    return make_pair(num,mx_skill_avg_i);
}



int main(){

    ifstream seed_list("seeds.txt");

    int mxseed = -1,mxsum=INF;
    float mnavg=9999.9f;
    //float mnavg=-1.0f;
    
    int mxsum_id = -1,f_name=-1;
    rep(i,6000){
        int seed; seed_list>>seed;
        pair<int,float> ret = file_open(i);
        //int sum = ret.second;
        float avg = ret.second;
        int id = ret.first;
        
        if(mnavg > avg){
            //mxsum = sum;
            mnavg = avg;
            mxseed = seed;
            mxsum_id = id;
            f_name = i;
        }
        //cout<<"seed: "<<seed<<" sum: "<<sum<<endl;
    }
    cout<<endl<<"seed: "<<mxseed<<" "<<f_name<<".txt "<<"id: "<<mxsum_id<<" sum: "<<mnavg<<endl;

    //file_open(1);
    //cout<<ans<<endl;
    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    return 0;
}
