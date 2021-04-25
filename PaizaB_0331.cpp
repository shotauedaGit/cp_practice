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


bool DBG=false;
//bool DBG=true;


int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int n,m;
    cin>>n>>m;

    string day;
    vector<bool> is_off(n,false);
    rep(i,n){
        cin>>day;

        if(day=="work"){
            is_off[i] = false;
        }else{
            is_off[i] = true;
        }
    }

    int maxlen=-1;
    vector<bool> is_off_sch = is_off;

    if(DBG){rep(i,n)cout<<is_off_sch[i]<<" ";}
    //cout<<endl;

    rep(i,n){
        int rest = m;
        int len=-1;
        int tmp_max_len=-1;
        is_off_sch = is_off;

        rep(j,n){
            if(i+j >= n)break;
            
            if(is_off_sch[i+j] == true){

            } else {
                is_off_sch[i+j]=true;
                rest--;
                if(rest==0)break;
            }
        }

        if(is_off_sch[0] == true)len=1;
        else len=0;
        tmp_max_len = len;

        if(DBG){rep(i,n)cout<<is_off_sch[i]<<" ";}
        //cout<<endl;

        rep1(k,1,n){
            
            if(!is_off_sch[k]){
                len=0;
            }else{
                if(is_off_sch[k] && is_off_sch[k-1]){
                    len++;
                    chmax(tmp_max_len,len);
                }else{
                    len=1;
                    chmax(tmp_max_len,len);
                }
            }
        }

        chmax(maxlen,tmp_max_len);
        if(DBG)cout<<"  max:"<<maxlen<<endl;

    }


    cout<<maxlen<<endl;
    //cout <<fixed<<setprecision(16)<< << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
