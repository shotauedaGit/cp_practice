#include <bits/stdc++.h>

using namespace std;

#define INF 1001001001  //int32_t
#define MOD 1000000007
#define MOD2 998244353

#define all(a)  (a).begin(),(a).end()

#define pb push_back
#define eb emplace_back
#define mkp make_pair

#define se second
#define fi first

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){

    bool flag=false;
    ll ans=0,sum=0;

    int h,w,k;
    cin >>h>>w>>k;
    vector<string> s(h);

    vector<bool> ch(h,false);

    vector<int> chi;
    chi.emplace_back(-1);

    vector<vector<int>> amt(h,vector<int>(w,0));

    for (int i = 0; i < h; i++){
        cin >>s[i];
        for (int j = 0; j < w; j++){
            
            if(s[i][j]=='#'){
                ch[i]=true;
                chi.emplace_back(i);
                break;
            }
        }
        
    }

    if(chi.back() != h-1)chi.back()=h-1;

    int p=0;
    int cnt=1;

    while(1){

        if(p+1 == chi.size()-1){

        for(int j = 0;j < w;++j){
            for(int i = chi[p+1]; i >= chi[p]+1; --i){

                amt[i][j]=cnt;
                
                if(s[i][j]=='#'){
                    cnt++;
                }
            }
        }

        bool isbreaked=false;
        for(int j = w-1;j >= 0;--j){
            for(int i = chi[p]+1; i <= chi[p+1]; ++i){
                if(s[i][j] == '#'){
                    isbreaked=true;
                    break;
                }
                --amt[i][j];
            }
            if(isbreaked)break;
        }

        }else{

        for(int j = 0;j < w;++j){
            for(int i = chi[p]+1; i <= chi[p+1]; ++i){

                amt[i][j]=cnt;
                
                if(s[i][j]=='#'){
                    cnt++;
                }
            }
        }

        bool isbreaked=false;
        for(int j = w-1;j >= 0;--j){
            for(int i = chi[p+1]; i >= chi[p]+1; --i){
                if(s[i][j] == '#'){
                    isbreaked=true;
                    break;
                }
                --amt[i][j];
            }
            if(isbreaked)break;
        }

        }


        ++p;
        if(p==chi.size()-1)break;
    }


    /*
    for (int i = 0; i < h; i++){

        for (int j = 0; j < w; j++){
            amt[i][j]=cnt;
            
            if(s[i][j]=='#'){
                cnt++;
            }
        }

        for (int j = w-1; j >= 0; --j){
            if(s[i][j] == '#')break;
            --amt[i][j];
        }
    }
    */

    //puts("\n");
    //for (int i = 0; i < chi.size(); i++)cout <<chi[i]<< " "; puts("\n");
    
    
    for (int i = 0; i < h; i++)
    {
        for (int j = 0;j < w; j++)
        {
            cout << amt[i][j] << " ";
        }
        cout <<endl;
    }
    



    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
