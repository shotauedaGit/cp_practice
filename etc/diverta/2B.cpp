#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=1;
    int n;
    int ans=0;
    int distx=0,disty=0;
    int MAXX=0,MAXY=0;
    int px=0,py=0;
    map<int,int> mx;
    map<int,int> my;

    map< pair<int,int> , int> map1;

    map<int,int>::iterator p;

    cin >>n;
    int x[n];
    int y[n];

    for (int i = 0; i < n; i++){
        cin >>x[i]>>y[i];
    }


    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            if(j==i)continue;
            distx = x[j]-x[i];

            p=mx.find(distx);

            if(p != mx.end()){  //m[] == p->second??
                mx[distx] += 1;

                if(mx[distx] > MAXX){
                    MAXX = mx[distx];
                    px = distx;
                }

            }else{

                mx[distx]=1;
                if(mx[distx] > MAXX){
                    MAXX = mx[distx];
                    px = distx;
                }
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            if(j==i)continue;
            disty = y[j]-y[i];

            p=my.find(disty);

            if(p != my.end()){  //m[] == p->second??
                my[disty] += 1;
                
                if(my[disty] > MAXY){
                    MAXY = my[disty];
                    py = disty;
                }

            }else{
                my[disty]=1;

                if(my[disty] > MAXY){
                    MAXY = my[disty];
                    py = disty;
                }
            }
        }
    }


    
    
    
    cout << n-min(MAXX,MAXY) <<endl;

    std::cout <<MAXX<<" "<<MAXY<< '\n';
    std::cout <<px<<" "<<py<< '\n';
    //cout <<fixed<<setprecision(16)<< ans <<endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
