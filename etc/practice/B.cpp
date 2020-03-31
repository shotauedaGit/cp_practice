#include <iostream>
using namespace std;
    

int main(){
    int a,b;
    cin >>a>>b;

    if((a*b)%2==0){
        cout << "Even" <<endl;
        return 0;
    }
    cout << "Odd" <<endl;
    return 0;
}
