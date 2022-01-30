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





int main(){

    bool flag=false;
    ll ans=0,sum=0;

    string N;
    cin>>N;

    vector<vector<int>> req;
    for(int i=1000; i<2000; i+=8 ){
        string s = to_string(i).substr(1);

        vector<int> reqi(10,0);

        for(char c:s){
            ++reqi[(int)(c-'0')];
        }

        //if(reqi[0] != 0)continue;
        req.push_back(reqi);
    }

    vector<int> freq(10,0);
    for(int i=0;i<N.size();++i){
        int d = (int)(N[i] - '0');
        ++freq[d];
    }



    for(vector<int> reqi:req){
        bool tmp_flg = true;

        rep(i,10){
            if( freq[i] < reqi[i] ){
                tmp_flg=false;
                break;
            }
        }

        if(tmp_flg){

            //rep(i,10) if(reqi[i] != 0)cout<<i<<"x"<<reqi[i]<<" ";
            //cout<<endl;

            flag = true;
            break;
        }
    }


    if(N.size() < 3){
        int nN = stoi(N);
        if(nN==8 
        || nN==16 || nN==61 
        || nN==24 || nN==42
        || nN==32 || nN==23
        || nN==40
        || nN==48 || nN==84

        || nN==56 || nN==65
        || nN==64 || nN==46
        || nN==72 || nN==27
        || nN==88
        || nN==96 || nN==69
        ) flag=true;
    }


    //cout<<ans<<endl;
    //cout <<fixed<<setprecision(16)<< << endl;

    if(flag)cout << "Yes" <<endl;
    else cout << "No" <<endl;

    return 0;
}
