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
    int mod=1000000007;
    int n,m,h=0;
    int ans=1;
    int add=0;
    cin >>n>>m;
    int a[m+2];



    int kaijyou[n+1];
    kaijyou[0]=1;kaijyou[1]=1;
    for (int i = 2; i <= n; i++){
        
        kaijyou[i]=modmul(kaijyou[i-1],i,mod);
    }
    //cout << kaijyou[n]<<endl;
    


    a[0]=-1;a[m+1]=n+1;
    for (int i = 1; i <= m; i++){
        cin >>a[i];
    }

    
    
    
    for (int i = 1; i < m; i++){
        if((a[i+1]-a[i]==1)){
            ans=0;
            cout << ans << endl;
            return 0;
        }
    }


    
    
    for (int i = m+1; i > 0; i--){
        h=a[i]-a[i-1]-2;

        //std::cout << "h="<<h;

        add=0;
        for (int k = 0; k <= h/2; k++){
            add += (moddiv(moddiv(kaijyou[h-k],kaijyou[h-2*k],mod),kaijyou[k],mod))%mod;
            add = add%mod;
        }

        //std::cout << "::add::" <<add<< '\n';

        ans = modmul(ans,add,mod);
        ans=ans%mod;
    }
    
    cout << ans <<endl;
    //cout <<fixed<<setprecision(16)<< ans <<endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
