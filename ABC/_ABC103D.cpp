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
    int n,m;
    cin >>n>>m;
    vector<int> skip(n);

    for (int i = 0; i < m; i++){
        int a,b;
        cin >>a>>b;
        --a;--b;
        skip[a] = (b-a);
    }
    

    for (int i = 0; i < n; i++){
        if(skip[i]!=0){
            int index=i;
            int j=0;
            while (skip[index]>0){
                ++j;
                skip[index+j]=1;
                --skip[index];
            }
            skip[index]=1;
        }
    }
    for (int i = 0; i < n; i++)cout <<skip[i];
    cout << endl;
    
    
    for (int i = 0; i < n; i++){
        if(skip[i]==1){
            ans++;
            while (skip[i]==1)i++;
        }
    }
    



    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
