#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int flag=1;
    int n;
    int ans=0;
    int distx=0,disty=0;

    int MAX=0;

    map< pair<int,int> , int> map1;
    map< pair<int,int> ,int>::iterator p;

    cin >>n;
    int x[n];
    int y[n];

    for (int i = 0; i < n; i++){
        cin >>x[i]>>y[i];
    }


    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(j==i)continue;
            distx = x[j]-x[i];
            disty = y[j]-y[i];

            auto temp = make_pair(distx,disty);

            p=map1.find(temp);

            if(p != map1.end()){  //m[] == p->second??
                map1[temp] += 1;

                if(map1[temp] > MAX){
                    MAX = map1[temp];

                    //std::cout <<"("<<x[i]<<","<<y[i]<<"to"<<x[j]<<","<<y[j]<<")";
                    //cout << temp.first<<","<<temp.second<<":"<<MAX<< endl;
                    
                    auto pq = temp;
                }

            }else{
                /*
                auto temp2 = make_pair(-1*distx,-1*disty);
                p=map1.find(temp2);
                if(p != map1.end()){
                    map1[temp2] += 1;
                    if(map1[temp2] > MAX){
                        MAX = map1[temp2];

                        std::cout <<"("<<x[i]<<","<<y[i]<<"to"<<x[j]<<","<<y[j]<<")";
                        std::cout << "(::gyaku::)" << std::endl;
                        cout << temp2.first<<","<<temp2.second<<":"<<MAX<< endl;
                    
                        auto pq = temp2;
                    }
                }*/

                map1[temp] = 1;

                if(map1[temp] > MAX){
                    MAX = map1[temp];
                    auto pq = temp;
                }

            }
        }
    }
    
    cout << n-MAX <<endl;

    //std::cout << << << << '\n';
    //cout <<fixed<<setprecision(16)<< ans <<endl;

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
