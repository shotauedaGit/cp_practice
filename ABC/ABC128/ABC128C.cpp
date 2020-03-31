#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int N,M,k,ans=0;
    int n;
    int flag=0;
    int i,j;
    int ok=0;
    cin >> N >> M;
    int data[M][N]={};
    int p[M]={};


    for (i = 0; i < M; i++){
        cin >>k;
        for (int j = 0; j < n; j++)data[i][j]=0;
        
        for (j = 0; j < k; j++){
            cin >>data[i][j];
            //data[i][j] -= 1;
        }
        
    }
    for (i = 0; i < M; i++){
        cin >> p[i];
    }

    for(n = 0; n < (1<<N); n++){
        ok=0;
        for (i = 0; i < M; i++){
            flag=0;
            j=0;
            while (data[i][j]>0 && j<N){
                flag += (n>>(data[i][j]-1))%2;
                j++;
            }
            if((flag%2) == p[i])ok++;
        }
        if(ok == M)ans++;
    }
    cout << ans <<endl;
    return 0;
}
