#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0;
    int n;
    pair<int,int> edge,edger;
    map<pair<int,int>,int> e;
    cin >> n;

    if(n%2==1){

        for (int i = 1; i < n; i++){
            e[make_pair(n,i)]=1;
        }
        n--;
    }

    for (int i = n; i > 0; i--){
        for (int j = 1; j <= n; j++){
            if(j == n+1-i || i==j)continue;
            edge = make_pair(i,j);
            edger = make_pair(j,i);

            if(e.find(edge) == e.end() && e.find(edger) == e.end()){
                e[edge]=1;
            }
        }
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << e.size() << endl;

    for (auto i =e.begin() ; i != e.end(); i++){
        cout << i->first.first << " " << i->first.second << endl;
    }
    

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
