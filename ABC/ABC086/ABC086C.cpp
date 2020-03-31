#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int pt=0,px=0,py=0;
    int t=0,x=0,y=0;
    int flag=1;
    int n;
    int ans;

    cin >>n;
    cin >>pt>>px>>py;

    if(((px+py)%2==0)){
        if((pt)%2==1)flag=0;
    }else{
        if((pt)%2==0)flag=0;
    }

    if((abs(px)+abs(py)) > (pt))flag=0;

    for (int i = 0; i < n-1; i++){
        cin >>t>>x>>y;

        if((abs(x-px)+abs(y-py))%2==0){   //距離は足りていてもパリティがおかしい
            if((t-pt)%2==1)flag=0;
        }else{
            if((t-pt)%2==0)flag=0;
        }
        
        if((abs(x-px)+abs(y-py)) > (t-pt))flag=0;  //距離が離れすぎている

        pt=t;
        px=x;
        py=y;
    }
    
    
    //cout << ans <<endl;
    if(flag==1)cout << "Yes" <<endl;
    else cout << "No" <<endl;
    
    return 0;
}
