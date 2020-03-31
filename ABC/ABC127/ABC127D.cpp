#include <bits/stdc++.h>
using namespace std;

#define INF ((1<<31)-1)  //int32_t
#define MOD 1000000007
#define MOD2 1000000007

#define all(a)  (a).begin(),(a).end()

#define mkp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

bool greater_paircmp(const pair<int,int> &a,const pair<int,int> &b){
    return a.first > b.first;
}

int main(){
    bool flag=true;
    ll ans=0,sum=0;
    
    int n,m;
    cin >>n>>m;
    vector<int> a(n);
    vector<pii> op(m),ideal;

    for (int i = 0; i < n; i++)cin>>a[i];

    for (int i = 0; i < m; i++){
        int b,c;
        cin >>b>>c;
        op[i] = mkp(c,b);
    }

    sort(all(a));
    sort(all(op),greater_paircmp);

    int pos = 0;
    int p=0;

    while(p < m){
        int c=op[p].first;
        int b=op[p].second;

        pos += b;
        
        if(pos >= n){
            ideal.pb(mkp(c,n));
            break;
        }

        ideal.pb(mkp(c,pos));
        p++;
    }

    int count=0;
    
    for (int i = 0; i < (int)ideal.size(); i++){
        
        //std::cout << "to::"<<ideal[i].second<< '\n';
        while (count < ideal[i].second)
        {
            ans += max(a[count],ideal[i].first);
            //std::cout <<count<<"::"<<a[count]<<"vs"<<ideal[i].first<< '\n';
            count++;
        }
    }

    while (count < n)ans += a[count++];
    

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
