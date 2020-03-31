#include <bits/stdc++.h>
using namespace std;

#define INF ((1<<30)-1)  //int32_t
#define MOD 1000000007
#define MOD2  

#define all(a)  (a).begin(),(a).end()

#define mkp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;



int main(){
    bool flag=true;
    ll ans=0,sum=0;

    int n,k;
    cin >>n>>k;
    
    int p[n],ren=1;

    vector<int> sorted;
    vector<int> first(k);
    list<int> first2;

    cin >>p[0];
    for(int i = 1; i < n; i++){
        cin >>p[i];

        if(p[i] >= p[i-1]){
            ren++;

            if(ren >= k && i-k+1 >= 0){
                sorted.push_back(i-k+1);
            }

        }else{
            ren=1;
        }
    }
    
    for (int i = 0; i < k; i++){
        first[i] = p[i];
        first2.push_back(p[i]);

        //srted.push(p[i]);
    }

    sort(all(first));
    first2.sort();


    //int mn=first[0],mx=first[k-1];
    

    int mn = *(first2.begin());
    int mx = *(--first2.end());
    //cout << "new max is " << mx<< " new min is " << mn<< endl;

    for (int i = 0; i <= n-k; i++){
        
        if(p[i+k] >= mx && p[i] == mn  && (i<n-k)){
            //--ans;

            //cout << i << " isnt unique!! (1)" <<endl;

        }else if(i >= k){

                if((binary_search(all(sorted),i)) && lower_bound(all(sorted),i-k+1) != sorted.begin()){
                    int num = lower_bound(all(sorted),i-k+1) - sorted.begin();

                    //cout << i << " isnt unique!! (2) , num= "<<num<<endl;
                }else{
                    ans++;
                    //cout << i << " is unique!!" <<endl;
                }

        }else{
            ans++;
            //cout << i << " is unique!!" <<endl;
        }

        if(i < n-k){
            auto er = lower_bound(all(first2),p[i]);
            first2.erase(er);
            //cout << "erased " << *er << endl;

            auto ins = lower_bound(all(first2),p[i+k]);
            first2.insert(ins,p[i+k]);
            //cout << "inserted " << p[i+k] << endl;

            mn = *(first2.begin());
            mx = *(--first2.end());
        }


        //cout << "new max is " << mx<< " new min is " << mn<< endl;
    
    }

    /*

    for (int i = 0; i < sorted.size(); i++)cout << sorted[i];
    cout <<'\n';

    */


    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
