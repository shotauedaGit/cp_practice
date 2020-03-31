#include <bits/stdc++.h>
using namespace std;

#define all(a)  (a).begin(),(a).end()

#define mkp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;



int main(){
    bool flag=true;
    ll ans=0,sum=0;
    int n,d,add=1,count=0;
    cin >>d>>n;

    int num=0;

    if(d == 0){
        add=1;
        while(1){
            num += add;
            if(num%100 == 0)continue;
            count++;
            if(count == n)break;
        }
        
    }else if(d == 1){
        add=100;
        
        while(1){
            
            num += add;
            if(num%10000 == 0)continue;
            count++;
            if(count == n)break;
        }

    }else{
        add=10000;
        while(1){
            num+=add;
            if(num % 1000000  == 0)continue;
            count++;
            if(count == n)break;
        }
    }
    



    //cout <<fixed<<setprecision(16)<< << endl;
    cout << num << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
