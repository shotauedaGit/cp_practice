#include <bits/stdc++.h>
using namespace std;
    

int checkrock(int p,int q,string s){
    int flag=0,pastf=0;
    int inArow=0;
    int maxinArow=0;

    
        for (int i = p-1; i < q; i++){
            pastf=flag;
            
            if(s[i]=='.'){
                
                flag=0;
                inArow=0;

            }else{
                flag=1;
                if(pastf==0)inArow=1;
            }

            if(pastf==1 && flag==1)inArow++;

            maxinArow = max(maxinArow,inArow);
        }

    return maxinArow;
}

int checkjimen(int p,int q,string s){
    int flag=0,pastf=0;
    int inArow=0;
    int maxinArow=0;

    
        for (int i = p-2; i <= q; i++){
            pastf=flag;
            
            if(s[i]=='#'){
                
                flag=0;
                inArow=0;

            }else{
                flag=1;
                if(pastf==0)inArow=1;
            }

            if(pastf==1 && flag==1)inArow++;

            maxinArow = max(maxinArow,inArow);
        }

    return maxinArow;
}

int main(){
    int n,a,b,c,d;
    int flag=0,pastf=0;
    int inArow=0;
    int maxinArow=0;
    string s;
    //int ans1=1,ans2=1,ans3=1;
    int ansall=1;

    cin >>n>>a>>b>>c>>d;
    cin >>s;


    if(d<c){
        if(checkjimen(b,d,s) <= 2)ansall=0;
        if(checkrock(a,c,s) >= 2)ansall=0;

        //if(s[d]=='#' || s[d-2]=='#')ansall=0;
    }else{

        if(checkrock(a,c,s) > 1)ansall=0;
        if(checkrock(b,d,s) > 1)ansall=0;

    }
    
    if(ansall==1)cout << "Yes" <<endl;
    else cout << "No" << endl;

    return 0;
}