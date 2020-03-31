#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0,sum=0;
    int n,m;
    
    string s;
    cin >>n>>s;

    stack<char> st;

    for (int i = 0; i < n; i++){
        if(s[i]==')' && !st.empty()){
            
            if(st.top()=='(')st.pop();
            else st.push(s[i]);

        }else{
            st.push(s[i]);
        }
    }
    
    while (!st.empty()){
        if(st.top()==')'){
            s = "(" + s;
        }else{
            s = s + ")";
        }
        st.pop();
    }
    


    //cout <<fixed<<setprecision(16)<< << endl;
    cout << s << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
