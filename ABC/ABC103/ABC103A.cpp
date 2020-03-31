#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=1;
    int task[3];
    int ans=0;

    cin >>task[0]>>task[1]>>task[2];
    sort(task,task+3);

    ans += abs(task[1]-task[0]) +abs(task[2]-task[1]);
    
    cout << ans <<endl;
    //cout <<fixed<<setprecision(16)<< ans <<endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
