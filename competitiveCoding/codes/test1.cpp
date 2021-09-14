// C++ initail code

#include<bits/stdc++.h>
#define REP(i,b) for (int i = 0; i < b; i++)
#define mt make_tuple
#define eb emplace_back
#define el endl // to display output at right place
#define F first
#define S second
#define ALL(x) (x).begin(), (x).end()
#define FOR(i,a,b,c) for (int i = a; i < b; i+=c)
#define MAT(v,row,col) vector<vi> v(row,vi (col,0)); // doubtful
// modular exponentiation
#define modexp ll power(ll x, ll y, ll p){ int res = 1; x = x % p; while(y>0){ if(y&1) res = (res*x) % p; y = y>>1; x = (x*x) % p; } return res; }

// impo functions
#define sumofdigits(sum,num) int sum = 0; while (n != 0) { sum = sum + n % 10; n = n/10; }
#define int2str(str,n) n=boost::lexical_cast<int>(str);
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
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

  // sum the numbers
  template<class T>
      auto sum(T a) {return a;}
  template<typename T, typename... Args>
  auto sum(T a, Args... args) { return a + sum(args...); }

  // display all the content 
  template<class T>
  void print(T a){
      cout<<a<<"\n";
      }
  template<typename T,typename... types>
  void print(const T& a,const types& ... args){
    cout<<a<<",";
    print(args...);
      }

  // vector print template

  template<typename T1,typename T2>ostream& operator<<(ostream& os,pair<T1,T2> ptt){
      os<<ptt.first<<","<<ptt.second;
      return os;
      }


  template<typename T>ostream& operator<<(ostream& os,vector<T> vt){
  os<<"{";    for(auto i:vt)
          os<<i<<","; os<<"}"; return os;
  }


// ******************* useful functions *******************

inline double log(ll a,ll b){
    return log10(a)/log10(b);
}


// ***************************** Code ***********************

template<typename T,typename T1>
void displayVector(vector<T> var,T1 s){
      cout<<"\n "<<s<<" \n";
      for (auto a: var)
      {
        cout<<a<<" ";
      }
      cout<<"\n";
    }

int generate_vector(vll &arr,bool startEven){
	//  two pointer method
	int left=0,right=0;
	int count =0 ;
	int L = arr.size();
	// startEven index and value parity to be same
	while(left < L ){

		if( ( (arr[left] & 1) == (left & 1) ) != startEven){
			right = max(right,left+1);
			// cout<<"left -> "<<left<<" right -> "<<right<<"\n";
			while(right < L ){
				if(  (arr[right] & 1) == (arr[left]&1) ){
					right++;
				}
				else{
					//  swap
					// cout<<"doing swap";
					// debug2(left,right);
					int temp = arr[right];
					arr[right] = arr[left];
					arr[left] = temp;
					count += (right-left);
					break;
				}
			}
			
		}
		left++;
		// displayVector<ll,string> (arr,"inner");
		// debug2(left,right);
	}
	return count;
}
    
int run(){
    ll n ,maxy =-8;
    cin>>n;
    vll v(n);
    REP(i,n) cin>>v[i];
	int odd=0,even=0;
	REP(i,n){
		if(v[i]&1) odd++;
		else even++;
		v[i] = v[i]%2;
	}
	if (abs(odd-even) > 1) return -1;

	
	//  start with odd
	vll v_odd(ALL(v));
	vll v_even(ALL(v));

	int val_odd = 1e9+17;
	int val_even = 1e9+17;
	// cout<<"check\n";
	// debug2(odd,even);
	if(odd==even){

	val_odd = generate_vector(v_odd,false);
	val_even = generate_vector(v_even,true);
	// debug2(val_odd,val_even);
	}
	else if (odd > even){
		 val_odd = generate_vector(v_odd,false);
	}
	else {
		 val_even = generate_vector(v_even,true);
	}
	// displayVector<ll,string>(v_even,"start");
	// val_even = generate_vector(v_even,true);
	// displayVector<ll,string>(v_even,"end");
	return min(val_odd,val_even);      
}

int main()
{	
    fastio

    int t =1;
	cin>>t;

	while(t--){
		// cout<<"\n###############################\n";
    cout<<run()<<"\n";
  	}
	return 0;
}



// 5
// 3
// 6 6 1
// 1
// 9
// 6
// 1 1 1 2 2 2
// 2
// 8 6
// 6
// 6 2 3 4 5 1