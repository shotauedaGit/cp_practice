
#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int N;
    cin >>N;
    string data[N][3];
    string temp1,temp2;

    for (int i = 0; i < N; i++){
        cin >>data[i][0]>>data[i][1];
        data[i][2]=to_string(i+1);
    }
    
    for (int i = 0; i < N-1; i++){
        for (int j = N-1; j > i; j--){

            if( data[j][0] < data[j-1][0] ){
                
                temp1=data[j][0];
                data[j][0]=data[j-1][0];
                data[j-1][0]=temp1;

                temp1=data[j][1];
                data[j][1]=data[j-1][1];
                data[j-1][1]=temp1;

                temp1=data[j][2];
                data[j][2]=data[j-1][2];
                data[j-1][2]=temp1;

            }else if(data[j][0] == data[j-1][0]){

                if((atoi(data[j][1].c_str())) > (atoi(data[j-1][1].c_str()))){

                    temp1=data[j][0];
                    data[j][0]=data[j-1][0];
                    data[j-1][0]=temp1;

                    temp1=data[j][1];
                    data[j][1]=data[j-1][1];
                    data[j-1][1]=temp1;

                    temp1=data[j][2];
                    data[j][2]=data[j-1][2];
                    data[j-1][2]=temp1;
                }

            }
        
        }
        
    }

    for (int i = 0; i < N; i++){
        cout << data[i][2] <<endl;
    }
    
    
    return 0;
}
