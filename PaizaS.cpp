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

int figure_type(char c){
    if('a' <= c && c <= 'z'){
        return 1;
    }else if('0' <= c && c <= '9'){
        return 2;
    }else if(c== '(' ){
        return 3;
    }else if(c == ')'){
        return 4;
    }
    return 0;
}

bool debug = false;
void DBG(int pos,int tp,ll buf,ll mult){
    if(debug)cout<<"pos:"<<pos<<" type:"<<tp<<" buf:"<<buf<<" mult:"<<mult<<endl;
}



int main(){

    bool flag=false;
    ll ans=0,sum=0;

    string s;
    cin>>s;

    ll mult=1,buf_mult=1;
    
    stack<ll> cur_mult;
    unordered_map<char,ll> hist;

    int pos=0;
    while(pos < s.length()){
        int tp = figure_type(s[pos]);
        switch (tp)
        {
        case 1:
            hist[s[pos]] += mult;

            if(pos==0){}
            else{
                if(figure_type(s[pos-1]) == 2){
                    ll div=cur_mult.top();
                    mult /= div;
                    cur_mult.pop();
                }
            }

            //buf_mult=1;
            DBG(pos,1,buf_mult,mult);
            break;
        
        case 2:
            bool is_prevN;

            if(pos==0)is_prevN =false;
            else{
                if(figure_type(s[pos-1]) == 2)is_prevN = true;
                else is_prevN = false;
            }
            
            bool is_nextA;
            if(pos==(s.length()-1))is_nextA =false;
            else{
                if(figure_type(s[pos+1]) == 1)is_nextA = true;
                else is_nextA = false;
            }
            
            
            if(!is_prevN){
                buf_mult = (int)(s[pos] - '0');
            }else{
                buf_mult *= 10;
                buf_mult += (int)(s[pos] - '0');
            }

            if(is_nextA){
                    mult *= buf_mult;
                    cur_mult.push(buf_mult);
            }

            DBG(pos,2,buf_mult,mult);
            break;
        
        case 3:
            mult *= buf_mult;
            cur_mult.push(buf_mult);
            
            //buf_mult=1;
            DBG(pos,3,buf_mult,mult);
            break;
        
        case 4:
            mult /= cur_mult.top();
            cur_mult.pop();
            
            //buf_mult=1;
            DBG(pos,4,buf_mult,mult);
            break;

        default:
            cout<<"?"<<endl;
            break;
        }

        pos++;
    }


    for(char c='a';c<='z';c += 1){
        if(debug && hist[c]==0)continue;
        cout<<c<<" "<<hist[c]<<endl;
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;

    return 0;
}
