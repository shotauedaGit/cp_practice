#include <bits/stdc++.h>
using namespace std;

#define INF ((1<<30)-1)  //int32_t
#define MOD 1000000007
#define MOD2  

#define all(a)  (a).begin(),(a).end()

#define mkp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;



int main(){
    bool flag=true;
    ll ans=0,sum=0;

    int q;
    cin >>q;

    vector<int> pnum(100001);
    vector<int> qans(100001);
    fill(all(qans),0);

    vector<bool> prime(100001);
    fill(all(prime),true);
    prime[0]=false;prime[1]=false;

    for (int i = 2; i <= 100000; i++){

        if(prime[i]){
            for (int j = i*2; j <= 100000; j+=i)prime[j]=false;
        }
    }

    int count=0;
    
    /*
    for (int i = 0; i <= 100000; i++)
    {
        if(prime[i]){
            count++;
        }
        pnum[i]=count;
    }*/
    
    count=0;
    for (int i = 1; i <= 100000; i+=2){
        int j = (i+1)/2;

        if(prime[i]&&prime[j]){
            count++;
        }
        qans[i]=count;
    }
    



    for (int i = 0; i < q; i++){
        int l,r;
        cin >>l>>r;

        int a = qans[r] - qans[max(l-2,1)];
        cout << a << '\n';

    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
