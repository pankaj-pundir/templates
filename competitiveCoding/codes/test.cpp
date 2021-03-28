#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> prefixArray(vector<ll> arr){
    vector<ll> ans(arr.size(),0);
    ans[0] = arr[0];
    for(int i = 1; i < arr.size(); i++)
        ans[i] = arr[i]+ans[i-1];
    return ans;
}

// template<typename T,typename... types>
//   void print(const T& a,const types& ... args){
//     cout<<a<<",";
//     print(args...);
//       }

template<typename T,typename T1>
void displayVector(vector<T> var,T1 s){
      cout<<"\n "<<s<<" \n";
      for (auto a: var)
      {
        cout<<a<<" ";
      }
      cout<<"\n";
    }

ll run(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for( auto &i:v) cin>>i;
    
    ll mini[2] = {v[0],v[1]};
    ll cnt[2] = {1,1};
    ll sumy = v[0]+v[1];

    ll  minVal = sumy + mini[0]*(n-cnt[0])+mini[1]*(n-cnt[1]);

    for(int i=2; i<n; i++){
        sumy+=v[i];
        mini[i%2] = min(mini[i%2],v[i]);
        cnt[i%2]++;

    ll temp= sumy + mini[0]*(n-cnt[0])+mini[1]*(n-cnt[1]);
    minVal = min(temp,minVal);

    }
    return minVal;
    
}

int main(){
    int n ;
    cout<<2e7;
    // cin>>n;
    // while(n--){
    //     cout<<run();
    //     // vector<ll> vans= run();
    //     // for(int i = 0; i < vans.size(); i++)
    //     //     cout<<vans[i]<<" ";
    //     cout<<"\n";
    // }

}