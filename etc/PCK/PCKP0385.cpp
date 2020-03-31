#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0,sum=0;
    int n,rest=0;
    
    cin >>n;
    vector< pair <int,int> > arr(n);
    vector< pair <int,int> > ori(n);

    for (int i = 0; i < n; i++){
        int a;
        cin >>a;

        arr[i]=make_pair(a,i);
        ori[i]=make_pair(a,-1);
    }
    

    sort(arr.begin(),arr.end());

    for (int i = 0; i < n; i++){
        if(arr[i].second  != i){
            rest++;
        }
    }
    if(rest==0){
        cout << rest << endl;
        return 0;
    }

    for (int i = 0; i < n; i++){
        ori[arr[i].second].second=i;
    }
    


    int q;
    cin >>q;

    for (int i = 0; i < q; i++){
        int x,y;
        cin >>x>>y;
        x--;y--;

        if(ori[x].second==y)rest--;
        else if(ori[x].second == x)rest++;

        if(ori[y].second==x)rest--;
        else if(ori[y].second == y)rest++;

        swap(ori[x],ori[y]);

        if(rest==0){
            cout << i+1 << endl;
            return 0;
        }
    }

    //cout <<fixed<<setprecision(16)<< << endl;
    cout << "-1" << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
