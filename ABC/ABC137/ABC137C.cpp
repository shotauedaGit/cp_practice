#include <bits/stdc++.h>
using namespace std;
    

int main(){
    long long ans=0,sum=0;
    int n;
    cin >>n;

    //string s;
    vector<char> sarray(10);
    map<vector<char>,long long> sames;
    char c;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < 10; j++){
            cin >> c;
            sarray[j]=c;
        }

        sort(sarray.begin(),sarray.end());

        sames[sarray]++;
        /*
        for (int j = 0; j < 10; j++)
        {
            cout << sarray[i][j];
        }
        cout << endl;
        */
    }
    
    long long add=0;
    for(auto p : sames){
        
        if(p.second < 2){
            add=0;
        }else{
            add = ((p.second)*(p.second-1))/2;
        }

        ans += add;
    }
    


    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
