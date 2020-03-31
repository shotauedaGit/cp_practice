#include <bits/stdc++.h>

using namespace std;

#define INF ((1<<30)-1)  //int32_t
#define MOD 1000000007
#define MOD2 98

#define all(a)  (a).begin(),(a).end()

#define mkp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int modpower(int x,int n,int m){
    long long result=x;
    long long ans=1;
    int ans_int;

    while (n!=0){
        if(n%2==0){

            result = ((result%m)*(result%m))%m;
            n >>= 1;

        }else{
            ans = ((ans%m) * (result%m))%m;
            --n;

        }
    }
    ans_int=ans%m;
    return ans_int;
}


int modmul(int p,int q,int m){
    long long ans,pp=p,qq=q;
    int ans_int;
    ans=((pp%m)*(qq%m))%m;
    ans_int=ans%m;
    return ans_int;
}

int moddiv(int p,int q,int m){
    return modmul(p,modpower(q,m-2,m),m);
}

vector<int> modfact(int x,int m){
    vector<int> fact(x+1);
    fact[0]=1;
    
    for(int i = 1; i <= x; i++){
        fact[i] = modmul(fact[i-1],i,m);
    }

    return fact;
}

int modcomb(int n,int r,int m,vector<int> fact){  //aaaaa
    long long ans;
    int ans_int;

    int a = fact[n];
    int div = modmul(fact[r],fact[n-r],m);

    ans_int = moddiv(a,div,m);

    return ans_int;
}

int main(){

    bool flag=false;

    int ans=1,sum=0;

    int n,m,p;
    cin >>n>>m;
    vector<int> fact = modfact(n + 64,MOD);

    map<int,int> div;


    p = m;
    for (int i = 2; i <= sqrt(m); i++){
        while(p%i == 0){
            p /= i;
            div[i]++;
        }
    }

    if(p > 1){
        div[p]++;
    }
    
    for(auto d:div){
        int mul = modcomb(n + d.second - 1,d.second,MOD,fact);
        
        //cout <<d.first<<":"<<d.second<<"  " <<endl;
        //cout <<"mul = "<<mul<<endl;;

        ans = modmul(ans,mul,MOD);
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
