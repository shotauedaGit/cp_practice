#include <bits/stdc++.h>
using namespace std;
    

int main(){
    bool flag=true;
    long long ans=0,sum=0;
    int day=0;
    int n;
    cin >>n;

    vector<queue<int>> match(n);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-1; j++){
            int a;
            cin >>a;
            match[i].push(a-1);
        }
    }
    
    int numOfmatch = n*(n-1)/2;

    while(true){
        int today[n]={};
        bool matchdone=false;

        for (int i = 0; i < n; i++){
            if(match[i].empty())continue;

            int p=match[i].front();
            int q=match[p].front();

            if(i == q && (today[i]==0 && today[p]==0)){

                //cout <<i+1<<" vs "<<p+1<<"(rest :)"<<numOfmatch<<endl;

                match[i].pop();
                match[p].pop();
                today[i]=1;
                today[p]=1;
                numOfmatch--;
                matchdone=true;

            }
        }

        day++;

        if(matchdone==false){
            cout << -1 <<endl;
            return 0;
        }
        if(numOfmatch==0){
            break;
        }
    }
    


    //cout <<fixed<<setprecision(16)<< << endl;
    cout << day << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
