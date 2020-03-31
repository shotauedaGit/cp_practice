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

    int h,w;
    cin >>h>>w;
    vector<string> s(h);
    vector<vector<int>> num(h,vector<int>(w,0));

    for (int i = 0; i < h; i++){
        cin >>s[i];
    }
    

    for (int i = 0; i < h; i++){
        int st=0,j = st,count=0;

        while(j < w){
            //cout << i << " " << j << endl;
            
            count=0;
            st = j;

            if(s[i][j] == '.'){
                while(s[i][j] == '.' && j < w){
                    ++count;
                    if(++j >= w)break;
                }

                for (int k = st; k < j; k++){
                    num[i][k] += count;
                }

            }else{
                num[i][j] += count;
                ++j;
            }

        }
    }
    
    for (int j = 0; j < w; j++){
        int st=0,i = st,count=0;

        while(i < h){
            //cout << i << " " << j << endl;

            count=0;
            st = i;

            if(s[i][j] == '.'){
                while(s[i][j] == '.'){
                    //cout << i << " " << j << endl;
                    ++count;
                    if(++i >= h)break;
                }

                for (int k = st; k < i; k++){
                    num[k][j] += count;
                }

            }else{
                num[i][j] += count;
                ++i;
            }

        }
    }

    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            //cout << num[i][j] << " ";
            ans = max(ans,(ll)num[i][j]);
        }
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans-1 << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
