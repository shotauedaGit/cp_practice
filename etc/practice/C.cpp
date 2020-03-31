#include <iostream>
using namespace std;
    

int main(){
    char s[3];
    int n=0;

    cin >>s;

    if(s[0]=='1')n++;
    if(s[1]=='1')n++;
    if(s[2]=='1')n++;

    cout << n <<endl;

    return 0;
}