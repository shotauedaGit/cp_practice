#include <bits/stdc++.h>
using namespace std;
    

int main(){
    long long ans=0,sum=0;
    int n;
    
    cin >>n;
    int a[n],b[n];
    priority_queue<pair<int,int>> pq;

    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++){
        cin >> b[i];
        pq.push(make_pair(b[i],i));
    }


    int flag=0;
    int quit=0;

    /*
    while (pq.size()){
        cout << pq.top().first << ":" << pq.top().second << endl;
        pq.pop();
    }*/
    


    while(!pq.empty()){
            int i=pq.top().second;
            cout << pq.top().first << ":" << pq.top().second << endl;
            pq.pop();

            if(b[i]==a[i]){
                continue;

            }else if(b[i] < a[i]){
                puts("-1");
                return 0;
            }

            int l=i-1,r=i+1;

            if(i==0){
                l=n-1;
            }else if(i==n-1){
                r=0;
            }else{
                l=i-1;
                r=i+1;
            }

            if(b[i] > b[l]+b[r]){
                int add=b[i]/(b[l]+b[r]);
                ans += add;

                if( add < 1){
                        puts("-1");
                        return 0;
                }

                b[i] %= (b[l]+b[r]);
                
                if(a[i] > b[i]){
                    int sub=(a[i]-b[i]+(b[l]+b[r]-1))/(b[l]+b[r]);
                    ans -= sub;

                    if(sub < 1){
                        puts("-1");
                        return 0;
                    }

                    b[i] += sub*(b[l]+b[r]);
                }

                pq.push(make_pair(b[i],i));


            }else{
                puts("-1");
                return 0;
            }

    }

    cout << ans << endl;

    //cout <<fixed<<setprecision(16)<< << endl;
    

    //if(flag==1)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
