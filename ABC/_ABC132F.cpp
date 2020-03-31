#include <bits/stdc++.h>
using namespace std;

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


int main(){
    int mod = 1e9+7,res,rep=0,p=0;
    int ans=0;
    int n,k;
    cin >> n >>k;
    
    
    /*for (int i = 1; i <= n; i++){
        ans += modpower(n/i,k-1,mod);
        ans %= mod;
    }
    */ 


    res=1;
    p=n;
    while (p>0){
        rep=0;
        do{
            rep++;
            
        }while(n/(--p) == res);
        ans += modmul(rep,modpower(res,k-1,mod),mod);
        ans %=mod;
        res=n/p;

        if(res==n){
            ans += modpower(n,k-1,mod);
            ans %=mod;
            break;
        }
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;
    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
