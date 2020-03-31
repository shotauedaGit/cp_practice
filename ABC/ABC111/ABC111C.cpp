#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int ans=0;
    int n,num;
    int max1=0,max2=0;
    int index1,index2;
    cin >>n;
    
    int data1[(int)1e5+1]={};
    int data2[(int)1e5+1]={};


    for (int i = 0; i < n; i++){
        cin >>num;

        if(i%2==0){
            data2[num]++;
            if(data2[num]>max2){
                max2=data2[num];
                index2=num;
            }
        }else{
            data1[num]++;
            if(data1[num]>max1){
                max1=data1[num];
                index1=num;
            }
        }
    }
    sort(data1,data1+100001,greater<int>());
    sort(data2,data2+100001,greater<int>());

    if(index1==index2){
        ans=min((n-(data2[1]+max1)),(n-(max2+data1[1])));
    }else{
        ans=n-max2-max1;
    }
    cout << ans << '\n';
    return 0;
}
