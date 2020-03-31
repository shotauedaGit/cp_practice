#include <bits/stdc++.h>
using namespace std;
    
bool isOutOfRange(int i,int j,int w,int h){

    if(i<0 || i>=h)return true;
    if(j<0 || j>=w)return true;
    return false;
}

int main(){
    int flag=1;
    int tflag=0;
    int h,w;
    string s[h];

    cin >>h>>w;
    for (int i = 0; i < h; i++){
        cin >>s[i];
    }
    
    
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            tflag=0;

            if(s[i][j]=='.'){
                continue;
            }else{

                if(isOutOfRange(i-1,j,w,h)==false){
                    if(s[i-1][j]=='.')tflag++;
                }else{
                    tflag++;
                }
                
                if(isOutOfRange(i,j-1,w,h)==false){
                    if(s[i][j-1]=='.')tflag++;
                }else{
                    tflag++;
                }
                
                if(isOutOfRange(i,j+1,w,h)==false){
                    if(s[i][j+1]=='.')tflag++;
                }else{
                    tflag++;
                }
                
                if(isOutOfRange(i+1,j,w,h)==false){
                    if(s[i+1][j]=='.')tflag++;
                }else{
                    tflag++;
                }
                
            }
            if(tflag==4)flag=0;
        }
    }
    //cout << ans <<endl;
    //cout <<fixed<<setprecision(16)<< ans <<endl;

    if(flag==1)cout << "Yes" <<endl;
    else cout << "No" <<endl;
    
    return 0;
}
