#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0;
    int n;
    cin >> n;
    vector <int> a,order;
    int b;

    for (int i = 0; i < n; i++)
    {
        cin >>b;
        a.push_back(b);
    }

    for (int i = 0; i < n; i++){
        int lastin=-1;
        int j=0;
        
        for (auto p : a){
            if(a[j]==j+1){
                lastin=j;
            }
            j++;
        }
        
        if(lastin==-1){
            cout << lastin << endl;
            return 0;
        }else{
            order.insert(order.begin(),a[lastin]);
            a.erase(a.begin()+lastin);
        }
        
    }
    
    for (int i = 0; i < (int)order.size(); i++){
        cout << order[i] << '\n';
    }
    

    

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
