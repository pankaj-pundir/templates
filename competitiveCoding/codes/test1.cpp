#include<bits/stdc++.h>
#define REP(i,b) for (int i = 0; i < b; i++)
#define mt make_tuple
#define eb emplace_back
#define el endl // to display output at right place
#define F first
#define S second
#define ALL(x) (x).begin(), (x).end()
#define FOR(i,a,b,c) for (int i = a; i < b; i+=c)
#define MAT(v,row,col) vector<vi> > v(row,vi (col,0)); // doubtful
// modular exponentiation
#define modexp ll power(ll x, ll y, ll p){ int res = 1; x = x % p; while(y>0){ if(y&1) res = (res*x) % p; y = y>>1; x = (x*x) % p; } return res; }
// 2D matrix
#define v2(dp,r,value) vector<std::vector<int> > dp(r,std::vector<int> (r,value))

#define tr(c,i) for(typeof(c).begin() i = (c).begin(); i != (c).end(); i++)

// impo functions
#define sumofdigits(sum,num) int sum = 0; while (n != 0) { sum = sum + n % 10; n = n/10; }
#define int2str(str,n) n=boost::lexical_cast<int>(str);
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// debugging 
#define debug1(x) cerr<<#x<<" = "<<x<<"\n"
#define debug2(a,b) cout<<a<<" "<<b<<endl;
#define debug3(a,b,c) cout<<a<<" "<<b<<" "<<c<<"\n";


#define MOD 1000007
using namespace std;

typedef long long ll; 
typedef pair<int, int> pii; 
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<ll> vll;

// try to read it in a normal conventions

// ***************************  Templates *****************


void displayVector(vi var){
      cout<<"\n output \n";
      for (auto a: var)
      {
        cout<<a<<" ";
      }
      cout<<"\n";
    }

char back(string &s,int i){
    int n = s.length();
    if(i==0) return s[n-1];
    return s[i-1]; 
}

char front(string &s,int i){
    int n = s.length();
    if(i==n-1) return s[0];
    return s[i+1]; 
}


bool check(string &s,int i){
    // RRD
    if(s[i] == 'R'){
        if(front(s,i) == 'D' && back(s,i)=='R' ) return true;
    }
    if(front(s,i) == s[i] && back(s,i)==s[i]) return true;
    return false;
}

ll run(){
    ll n ,maxy =-8;
    cin>>n;
    string s;
    cin>>s;
    if(n<=2) return 0;

    int count = 0;
    int change =0;
    for(int i = 0; i<n;i++){

        if(back(s,i) != s[i] && !(s[i] == 'D' || back(s,i) == 'D')) {
            s[i] = 'D';
            s[(i+n-1)%n] = 'D';
            change++;
        }

    }

    if(change == 0){
        return floor(n/2);
    }
    int mpos = 0,pos ;

    while(s[mpos++] != 'D');
    mpos--;

    pos = (mpos+1+n)%n;
    char past = 'D'; 
    int tempCount= 0;


    // cout<<s<<pos<<"\n";

    while(pos != mpos){
        if(past == s[pos]){
            tempCount++;
        }
        else {
            
            if(past != 'D') {count += floor(tempCount/2);
            // cout<<tempCount<<" "<<count<<"\n";
            }
            tempCount =1;
            past = s[pos];
            

        }

        pos = (pos+1+n)%n;
        // cout<<"\n"<<pos<<"pos \n";
    }
    if(past != 'D')
    count += floor(tempCount/2);

    // for(int i = 0; i<n;i++){
    //         if(s[i]=='D') continue;
    //     // if(back(s,i) == 'R' && s[i] == 'L') {
    //     //     s[i] = 'D';
    //     //     s[(i+n)%n] = 'D';
    //     //     continue;
    //     // }

    //     if(check(s,i)) {
    //         if(s[i] == 'R') s[i] = 'L';
    //         else s[i] = 'R';
    //         count++;
    //     }
    // }

    return count;

      
}

int main()
{	
    fastio

    int t =1;
	cin>>t;
	while(t--){
    cout<<run()<<"\n";
  }
	return 0;
}

