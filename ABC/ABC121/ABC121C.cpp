#include <bits/stdc++.h>
using namespace std;

typedef struct strc{

    int val;
    int amount;

    strc(int v, int a){
        val = v;
        amount = a;
    }

}drinkinfo;


bool cmp(const strc &a,const strc &b){
    return a.val < b.val;
}



int main(){
    long long ans=0;
    int sum=0;
    int v,a;
    int n,m;
    cin >>n>>m;

    vector<drinkinfo> d;

    for (int i = 0; i < n; i++){
        cin >>v>>a;
        d.push_back(drinkinfo(v,a));
    }
    
    sort(d.begin(),d.end(),cmp);
    
    int i=0;
    while(sum <= m){
        if(i>=n)break;

        int buy=min(d[i].amount,m-sum);
        sum += buy;
        ans += (long long)buy*d[i].val;
        i++;
    }
    


    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
