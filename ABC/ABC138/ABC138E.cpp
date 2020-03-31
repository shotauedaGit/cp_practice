#include <bits/stdc++.h>
using namespace std;

#define all(a)  (a).begin(),(a).end()
#define MOD 1000000007;

typedef long long ll;

int main(){
    ll ans=0,sum=0;
    int n,count=0;
    string s,t;

    map<char,int> ms;
    map<char,vector<int>> msi;
    map<char,int> mt;
    cin >>s>>t;

    int slen=(int)s.length();
    int tlen=(int)t.length();
    for (int i = 0; i < slen; i++){
        ms[s[i]]++;
        msi[s[i]].push_back(i+1);
    }

    for (int i = 0; i < tlen; i++){
        mt[t[i]]++;
    }
    
    for(auto p : mt){
        if(ms[p.first] < 1){
            cout << "-1" << '\n';
            return 0;
        }
    }

    int ansinner=ans%slen;

    for (int i = 0; i < tlen; i++){

        int num=msi[t[i]].size();
        int j = (upper_bound(all(msi[t[i]]),ansinner))-(msi[t[i]].begin());

        if(j >= num){
            count++;
            ansinner=msi[t[i]][0];
        }else{
            ansinner=msi[t[i]][j];
        }

        ans = (ll)(ansinner + (ll)slen*count);
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
