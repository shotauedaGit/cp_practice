#include <bits/stdc++.h>
using namespace std;

#define INF ((1<<31)-1)  //int32_t
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

    vector<string> grid(h);
    vector<vector<bool>> pri(h,vector<bool>(w));

    for (int i = 0; i < h; i++)
    {
        cin >>grid[i];
        for (int j = 0; j < w; j++)
        {
            pri[i][j]=true;
        }
        
    }
    

    for (int i = 0; i < h; i++)
    {
        bool same=true;
        for (int j = 0; j < w; j++)
        {
            if(grid[i][j]=='#')same=false;
        }


        if(!same)continue;
        //cout << "row" <<i+1<<endl;
        for (int k = 0; k < w; k++)
        {
            pri[i][k] = false;
        }
    }
    
    for (int i = 0; i < w; i++)
    {
        bool same=true;
        for (int j = 0; j < h; j++){
            if(grid[j][i]=='#')same=false;
        }

        if(!same)continue;

        //cout << "col" <<i+1<<endl;
        for (int k = 0; k < h; k++){
            pri[k][i] = false;
        }
    }

    for (int i = 0; i < h; i++)
    {
        bool printed=false;
        for (int j = 0; j < w; j++)
        {
            if(!pri[i][j])continue;
            cout << grid[i][j];
            printed=true;
        }
        if(printed)cout << endl;
    }
    



    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
