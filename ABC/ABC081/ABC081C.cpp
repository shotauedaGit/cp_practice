#include <bits/stdc++.h>
using namespace std;

struct strc{
    string keys;
    int keyv;
    int val;

    strc(int kv,int v){
        keyv=kv;
        val=v;
    }

    strc(string s,int kv,int v){
        keys=s;
        keyv=kv;
        val=v;
    }
};

bool cmp(const strc &a,const strc &b){
    return a.val<b.val;
}

int main(){
    map<int,int> m1;
    vector<strc> v1;

    int ans=0;
    int n,a,k;
    cin >> n>>k;
    int spe=0;

    for (int i = 0; i < n; i++){
        cin >>a;
        if(m1.find(a) != m1.end())m1[a]++;
        else m1[a]=1;
    }

    for (auto i = m1.begin(); i != m1.end(); i++){
        v1.push_back(strc(i->first,i->second));
        spe++;
    }
    
    sort(v1.begin(),v1.end(),cmp);

    for (int i = 0; i < spe-k; i++){
        ans += v1[i].val;
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
