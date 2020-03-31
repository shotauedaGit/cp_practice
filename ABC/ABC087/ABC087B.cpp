#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int a,b,c,x;
    int ans=0;
    cin >> a>>b>>c>>x;

    for (int i = 0; i <= c; i++){
        for (int j = 0; j <= b; j++){

            int k=(x-(50*i+100*j))/500;
            if(x == 50*i+100*j+500*k  && a>=k && k>=0 ){
                ans++;
                //cout << k << " ";
            }

            /*
            for (int k = 0; k <= a; k++){
                if(x == 50*i+100*j+500*k)ans++;
            }
            */
        }
        //std::cout << '\n';
    }

    cout << ans <<endl;
    return 0;
}
