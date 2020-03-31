#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=0;
    int n;
    int data1,data2;
    int ans=0;

    pair<int,int> p;
    map<pair<int,int>,int> datamap;

    cin >>n;

    for (int i = 0; i < n; i++){
        cin >>data1>>data2;
        p=make_pair(data1,data2);

        if((datamap.find(p)) == datamap.end()){
            if((datamap.find(make_pair(data2,data1))) == datamap.end()){
                ans++;
                datamap[p]=1;
            }
        }
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
