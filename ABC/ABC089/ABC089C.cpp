#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int64_t ans=0,temp;
    int n;
    cin >> n;
    int data[5]={};
    string s;

    for (int i = 0; i < n; i++){
        cin >>s;

        switch (s[0]){
        case 'M':
            data[0]++;
            break;
        case 'A':
            data[1]++;
            break;
        case 'R':
            data[2]++;
            break;
        case 'C':
            data[3]++;
            break;
        case 'H':
            data[4]++;
            break;
        default:
            break;
        }
    }
    
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if(j==i)continue;
            temp=1;
            for (int k = 0; k < 5; k++){
                if(k==j || k==i)continue;
                temp *= data[k];
            }
            ans += temp;
        }
        
    }
    

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans/2 << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
