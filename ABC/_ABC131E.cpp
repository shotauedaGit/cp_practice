#include <bits/stdc++.h>
using namespace std;

struct v{
    int v1;
    int v2;

    v(int ver1,int ver2){
        v1=ver1;
        v2=ver2;
    }
};

int findmaxp(int k){
    int i=0,p;
    while ((i*(i+1)/2)<=k)i++;
    i--;
    if(i==0){
        return -1;
    }
    return i;
}

int sumi(int i){
    return i*(i+1)/2;
}


int main(){
    int n,k,i=0;
    int next;
    int p;
    cin >> n >> k;
    int rest = k;
    int reqv=2;

    //vector<v> hen;
    vector<int> repnum;

    while (rest > 0){
        p=findmaxp(rest);
        if(p == -1)break;
        
        if(i>100)break;
        repnum.push_back(p);
        
        rest -= sumi(p);
        reqv += p;

        if(reqv > n){
            cout << -1 << endl;
            return 0;
        }
        i++;
    }

    for (int i = 0; i < (int)repnum.size(); i++){
        cout << repnum[i] << '\n';
    }
    
    


    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
