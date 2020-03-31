#include <bits/stdc++.h>

using namespace std;

#define INF ((1<<30)-1)  //int32_t
#define MOD 1000000007
#define MOD2 


#define PI 3.14159265358979323846264

#define all(a)  (a).begin(),(a).end()

#define mkp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){

    bool flag=false;

    double ans=0,sum=0;
    
    double a,b,x;
    cin >>a>>b>>x;
    double theta=0;

    if(x >= a*a*b/2){

        double p = (a*a*b-x)/(a*a*a/2);
        theta = atan(p);



    }else{
        double p = a*b*b/(2*x);
        theta = atan(p);
    }

    ans = (theta/(2*PI))*360;

    //cout <<fixed<<setprecision(16)<< << endl;
    cout <<fixed<<setprecision(16)<< ans << endl;
    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
