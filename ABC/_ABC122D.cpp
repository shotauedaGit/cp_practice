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

int main(){
    int m=1000000007;
    int ans=0;
    int n;
    cin >> n;
    ans = modpower(4,n,m);
    ans = (ans - modmul(3*n-6,modpower(4,n-3,m),m))%m;
    ans = (ans - modmul(2*n-6,modpower(4,max(3,n-4),m),m))%m;


    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
