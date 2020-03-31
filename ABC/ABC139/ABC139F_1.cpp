#include <bits/stdc++.h>
using namespace std;
    

int main(){
    bool flag=true;
    double ans=0,sum=0;
    int n;
    cin >>n;
    vector<pair<long long,pair<int,int>>> dp(n+1);

    dp[0]=make_pair(0,make_pair(0,0));
    int x,y;

    for (int i = 0; i < n; i++){
        cin>>x>>y;
        long long nx=dp[i].second.first + x;
        long long ny=dp[i].second.second + y;
        long long dis = dp[i].first;

        long long ndissq = nx*nx + ny*ny;

        long long ndisz = (long long)sqrt(ndissq);
        
        long double ndisfrac = sqrtl(ndissq - ndisz*ndisz);
        long double ndis=ndisfrac + ndisz;

        //cout << "x,y=" <<nx<<" "<<ny<< " ndis:"<<ndis<<'\n';

        if(ndissq >= dis){
            dp[i+1]=make_pair(ndissq,make_pair(nx,ny));
        }else{
            dp[i+1]=dp[i];
        }
    }
    
    long double ndisz = (int)sqrt(dp[n].first);
    long double ndisfrac = sqrtl(dp[n].first - ndisz*ndisz);



    //cout <<fixed<<setprecision(32)<< ndisz + ndisfrac<< endl;
    cout <<fixed<<setprecision(32)<< sqrtl(dp[n].first) << endl;

    //cout <<  << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
