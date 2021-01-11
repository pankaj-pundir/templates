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

vector<int> solve(){
    ll n,k;
    cin>>n>>k; 
    vector<int> v(n);
    for(auto &i: v) cin>>i;

    while(k--){
        modif(v,giveMax(v));
        if(allPos(v)){
            // cout<<"all pos\n";
            if(k&1){
                modif(v,giveMax(v));
                return v;
            }
            else return v;
        }
        
        // k--;
    }
    return v;

}

int main(){
    int t,n;
    cin>>t;
    while(t--){
        vector<int> vv = solve();
        for(auto i: vv){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}