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
    long long ans=1;
    int mod=1000000007;
    int n;
    string s;
    map<char,int> m;
    cin >>n>>s;

    for (int i = 0; i < n; i++){
        m[s[i]]++;
    }
    

    for(auto p:m){
        ans = modmul(ans,p.second+1,mod);
    }
    ans = (ans-1)%mod;

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
