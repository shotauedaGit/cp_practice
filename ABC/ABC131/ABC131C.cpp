#include <bits/stdc++.h>
using namespace std;

int64_t GCD(int64_t m,int64_t n){
    int64_t big,small;
    int64_t p=-1;
    big=max(m,n);
    small=min(m,n);

    while(1){
        p=big%small;
        if(p==0)break;
        big=small;
        small=p;
    }
    
    return small;
}

int main(){
    int64_t a,b,c,d;
    int64_t l;
    cin >> a>>b>>c>>d;
    int flag=0;
    int64_t numc,numd,numl;
    int64_t ans=0;

    l= (c*d)/GCD(c,d);

    if(a%c==0){
        numc = (b/c)-(a/c)+1;
    }else{
        numc=(b/c)-(a/c);
    }

    if(a%d==0){
        numd = (b/d)-(a/d)+1;
    }else{
        numd=(b/d)-(a/d);
    }

    if(a%l==0){
        numl = (b/l)-(a/l)+1;
    }else{
        numl=(b/l)-(a/l);
    }

    ans = (b-a+1) -numc -numd +numl;

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
