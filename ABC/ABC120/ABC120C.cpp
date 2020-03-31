#include <bits/stdc++.h>
using namespace std;
    

int main(){
    string s;
    cin >> s;
    stack <char> st;
    int ans=0;

    st.push(s[0]);
    for (int i = 1; i < s.length(); i++){
        if(st.size()>0){
            
            if(st.top() == s[i]){
                st.push(s[i]);
            }else{
                st.pop();
                ans +=2;
            }

        }else{
            st.push(s[i]);
        }
    }
    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
