#include <bits/stdc++.h>

using namespace std;

#define INF 1001001001  //int32_t
#define MOD 1000000007
#define MOD2 998244353

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
    
    for(int i = 0; i < x; i++){
        fact[i+1] = modmul(fact[i],i+1,m);
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
    ll ans=1,sum=0;

    int n;
    cin >>n;


    vector<int> fact;
    fact = modfact(n+5,MOD2);
    map<int,int> dm;

    for (int i = 0; i < n; i++){
        int d;
        cin >>d;

        if(i==0 && d!=0){
            puts("0");
            return 0;
        }

        dm[d]++;
    }


    if(dm[0] != 1){
        puts("0");
        return 0;
    }


    int pastn;
    int restv = n;

    int must = 1;
    for(auto num : dm){
        int nown = num.second;

        if(num.first==0){
            pastn = num.second;
            restv -= num.second;
            continue;
        }

        if(restv < nown){
            puts("0");
            return 0;
        }else if( num.first != must){
            puts("0");
            //cout <<num.first<<"!="<<must<<endl;
            return 0;
        }

        
        //int mul1 =  modpower(nown+1,pastn-1,MOD2);
        //int mul2 = modcomb(restv,nown,MOD2,fact);
        int mul3 = modpower(pastn,nown,MOD2);
        //int div1 = fact[pastn-1];
        
        /*
        mul2=1;
        div1=1;
        */

        ans = modmul(ans, mul3 ,MOD2);

        //ans = modmul(ans, mul2 ,MOD2);
        //ans = moddiv(ans,div1,MOD2);

        //cout << mul1 << " and " <<mul2<<" and "<<div1<<endl;
        //cout << " n=" << restv <<" r="<< nown <<endl;

        pastn = nown;
        restv -= nown;

        must++;
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //cout <<fact[1]<<fact[5]<<fact[6]<<fact[n];

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
