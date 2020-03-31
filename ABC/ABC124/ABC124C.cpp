#include <iostream>
#include <vector>
using namespace std;
    

int main(){
    int a=0,b=0,ans=0;
    string s;
    char c;

    cin >> s;
    for (int i = 0; i < s.length(); i++){
        if(i%2==1)c='1';
        else c='0';
        
        if(s[i]==c){
            a++;
        }else{
            b++;
        }
    }
    
    ans = min(a,b);
    cout << ans <<endl;
    return 0;
}
