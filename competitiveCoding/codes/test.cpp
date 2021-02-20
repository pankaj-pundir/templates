#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
typedef long long ll;

ll BinPow(ll a,ll b,ll m){
    ll ans = 1;
    while(b){
        if(b & 1)ans = ans *1ll* a % m;
        a = a *1ll* a % m;
        b >>= 1;
    }
    return ans;
	}

void displayVector(vector<int> var){
      cout<<"\n output \n";
      for (auto a: var)
      {
        cout<<a<<" ";
      }
      cout<<"\n";
    }

bool allPos(vector<int> &v){
    int mini = INT_MAX;
    for(auto i:v){
        if(i<0)
        return false;
        mini = min(mini,i);
    }
    if(mini == 0)   
        return true;
    return false;
}

int giveMax(vector<int> &v){
    int maxy = INT_MIN;
    for(auto i:v){
        maxy = max(maxy,i);
    }
    return maxy;
}

void modif(vector<int> &v,int maxy){
    for(auto &i:v){
        i = maxy - i;
    }
}

ll solve(){
    ll n,k;
    cin>>n; 
    vector<int> v(n);

    for(auto &i: v) cin>>i;
    // cout<<"val is "<<n;
    if (n<=3) {
        return 0; 
    }
    vector<int> ans(n-2,0);
    
    int count = 0;
    bool harsh = false;
    for(int i =0;i < n-2; i++){
        if (v[i+1] > v[i] && v[i+1] > v[i+2]) {
            if(v[i]==v[i+2]) harsh = true;
            ans[i] =1; 
            count++;
        }
        else if(v[i+1] < v[i] && v[i+1] < v[i+2]){
            if(v[i]==v[i+2]) harsh = true;
            ans[i] = -1; 
            count++;
        }
        
    } 
    displayVector(ans);
 
    int maxSub = 1;

    for(int i =0;i < n-3; i++){
        if(ans[i] == -ans[i+1]) {
            maxSub = max(maxSub,2);
            
        }
        if(i<n-4 && (v[i+1] == v[i+3])){
            maxSub = max(maxSub,3);
        }
    }

    return max(count-maxSub,0);

}

int main(){
    int t,n;
    cin>>t;
    while(t--){
    cout<<solve();
        cout<<"\n";
    }
}