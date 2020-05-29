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

typedef pair<int,int> P;
typedef pair<int,P> iP;
typedef pair<P,P> PP;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){

    bool flag=false;

    int h,w,k;
    cin>>h>>w>>k;

    vector<vector<char>> ck(h,vector<char>(w));
    vector<vector<int>> ans(h,vector<int>(w,0));
    
    vector<bool> st(h,false);
    vector<int> rowgl(h,0);

    rep(i,h){
        rep(j,w){
            cin>>ck[i][j];
            if(ck[i][j]=='#')st[i]=true;
        }
    }


    bool fistb=false;
    int rowglcnt=0;
    vector<vector<int>>rowlist(1);

    rep(i,h){
        if(st[i] && !fistb){
            fistb=true;
        }
        else if(st[i]){
            rowglcnt++;
            rowlist.push_back( vector<int>() );
        }
        rowgl[i] = rowglcnt;
        rowlist.back().push_back(i); 

        //db2(i,rowgl[i]);ln;
    }


    int glcnt=0;
    rep(i,h){
        if(!st[i])continue;
        ++glcnt;

        fistb=false;
        rep(j,w){

            if(ck[i][j]=='#' && !fistb){
                fistb=true;
            }else if(ck[i][j]=='#'){
                glcnt++;
            }

            ans[i][j] = glcnt;
        }

        int curgl = rowgl[i];
        for(int row : rowlist[curgl]){
            if(row!=i)ans[row]=ans[i];
        }
    }

    rep(i,h){
        rep(j,w)cout<<ans[i][j]<<" ";
        ln;
    }

    /*
    int cnt=0;
    for(vector<int> vc:rowlist){
        cout<<cnt<<"  :   ";
        for(int rowi:vc)cout<<rowi<<" ";
        ++cnt;ln;
    }
    */



    //cout <<fixed<<setprecision(16)<< << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    return 0;
}
