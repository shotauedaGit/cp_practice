#include <bits/stdc++.h>

using namespace std;

#define INF 1001001001
#define LINF 1001001001001001001
#define MOD 1000000007
#define MOD2 998244353

#define all(a)  (a).begin(),(a).end()
#define dig(n)  to_string(n).length()

#define pb push_back
#define eb emplace_back
#define mkp make_pair

#define se second
#define fi first

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,pii> ppii;

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int n;

    cin >>n;
    vector<vector<pii>> say(n);

    for (int i = 0; i < n; i++){
        int ai;
        cin >>ai;

        for (int j = 0; j < ai; j++){
            int x,y;
            cin >>x>>y;

            say[i].emplace_back(--x,y);
        }
    }

    for (int i = 0; i < (1<<n); i++){

        map<int,int>tru,fal;
        int tmp=0;
        for (int j = 0; j < n;j++){
            if((i>>j)%2==1){
                tru[j]=1;
                ++tmp;

                //cout<<1<<",";
            }else{
                fal[j]=1;
                
                //cout<<0<<",";
            }
        }
        //cout << endl;

        bool br=false;
        for (int j = 0; j < n; j++){

            if(tru[j]==1){
                for(pii s:say[j]){
                    if(s.se == 0){
                        if(tru[s.fi]==1){
                            br=true;
                            //cout <<"true:"<<j<<" ,but "<<s.fi<<" also true"<<endl;
                            break;
                        }
                    }else{
                        
                        if(fal[s.fi]==1){
                            br=true;
                            //cout <<"true:"<<j<<" ,but "<<s.fi<<" is fal"<<endl;
                            break;
                        }
                    }
                }
            }
        }
        if(br)continue;
        ans = max(ans,(ll)tmp);
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
