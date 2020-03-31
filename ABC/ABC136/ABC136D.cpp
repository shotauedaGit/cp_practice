#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0,sum=0;

    string s;
    cin >>s;
    int n[s.size()]={};

    int i=0;


    while (i < s.size()){
        int r,l;
        int rn,ln;
        
        if(s[i]=='R'){
            r=i;

            while (s[i]!='L'){
                i++;
            }

            l=i;
            rn=i-r;
            r=i-1;

            if(i==s.size()-1){
                ln=1;
                i++;
            }else{

                while (s[i]!='R' && i<s.size()){
                    i++;
                }
                
                ln = i-l;
            }

            //cout << r<<l<< s[i] <<endl;


            n[r] = rn - (rn/2) + (ln/2);
            n[l] = ln - (ln/2) + (rn/2);

        }
    }
    


    //cout <<fixed<<setprecision(16)<< << endl;
    for (int j = 0; j < s.size(); j++)
    {
        cout << n[j] << ' ';
    }
    cout << endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
