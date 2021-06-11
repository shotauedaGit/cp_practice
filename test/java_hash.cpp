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

chrono::system_clock::time_point  start;
void Timer_start(){start = std::chrono::system_clock::now();}
double Timer_end(){
    auto end = std::chrono::system_clock::now();
    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count(); //処理に要した時間をミリ秒に変換
    return elapsed;
}

#define LEN 2

int h(unsigned char *s){
    int hs=0;

    for(int i=0;i<LEN;++i){
        unsigned char c = s[i];
        hs = 31*hs + c;
    }

    return hs;
}

int h(vector<int> s){
    int hs=0;
    for(int i=0;i<s.size();++i){
        unsigned char c = s[i];
        hs = 31*hs + c;
    }
    return hs;
}

string same_hash(string s){
    vector<int> sv;
    int len=s.length();

    rep(i,len)sv.pb( (unsigned char)s[i] );

    int mode =rand()%2;
    int idx = rand()%(len-1);


}


int main(){

    srand(time(NULL));
    bool flag=false;
    ll ans=0,sum=0;

    int n,m;


    int cnt=0,lim=100,len=-1;
    
    vector<int> sv;
    string s = "abcdefgh"; len = s.length();

    for(unsigned char c:s){
        sv.pb((int)c);
    }

    stack< vector<int> > hs;hs.push(sv);

    while( !hs.empty()  && cnt<lim){
        vector<int> cur,tmp;
        cur = hs.top();
        
        for(int i=0; i<len-1;++i){
            if(cnt>=lim)break;

            tmp = cur;
            while(true){
                ++tmp[i];
                tmp[i+1]-=31;

                if(!(tmp[i] <=126 && tmp[i+1]>=32 &&cnt<lim))break;
                hs.push(tmp);
                cnt++;
            }

            tmp=cur;
            while(true){
                --tmp[i];
                tmp[i+1]+=31;

                if(!(tmp[i] >=32 && tmp[i+1]<=126 &&cnt<lim))break;
                hs.push(tmp);
                cnt++;
            }
        }
    }



    int c=0;
    while( !hs.empty()){
        c++;
        vector<int> vi = hs.top();hs.pop();

        cout<<c<<": ";
        rep(i,len){
            cout<<(unsigned char)vi[i];
        }
        cout<<"  hash: "<< h(vi) <<endl;
    }




    /*
    string in;
    while(in != "q"){
        cin>>in;
        cout<<h(in)<<endl;
    }
    */

    //cout<<ans<<endl;
    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
