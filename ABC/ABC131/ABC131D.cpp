#include <bits/stdc++.h>
using namespace std;

struct strc{
    int val1;
    int key;

    strc(int v1,int k){
        val1=v1;
        key=k;
    }
};

bool cmp(const strc &a,const strc &b){
    return a.key<b.key;
}


int main(){
    int flag=1;
    int n = 0;
    int a,b,t=0;;
    cin >> n;
    vector<strc> tasks;
    for (int i = 0; i < n; i++){
        cin >>a>>b;
        strc task(a,b);
        tasks.push_back(task);
    }

    sort(tasks.begin(),tasks.end(),cmp);
    
    for (int i = 0; i < n; i++){
        t += tasks[i].val1;
        if(t > tasks[i].key)flag=0;
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    if(flag==1)cout << "Yes" <<endl;
    else cout << "No" <<endl;
    
    return 0;
}
