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
    
void run(int head){
    ll n ,maxy =-8;
    cin>>n;
	char dp[n][n] = {};
	// MAT(dp,n,n);

	vi row(n,0),col(n,0);
	int ext = 500000;
	REP(i,n){
		REP(j,n){
			cin>>dp[i][j];
			//  row
			if(row[i] != ext){
				if(dp[i][j] == 'O')
				row[i] = ext;
				if(dp[i][j] == '.')
				row[i]++;
			}

			//  col
			if(col[j] != ext){
				if(dp[i][j] == 'O')
				col[j] = ext;
				if(dp[i][j] == '.')
				col[j]++;
			}
		}
	}
	int mini = ext; //mini_c = ext;
	REP(i,n){
		mini = min(mini,min(row[i],col[i]));
	}
	int count_r=0,count_c=0;
	REP(i,n){
		if (row[i] == mini) {
			count_r++;
			if(mini == 1){
				bool flag = false;
				for(int k =0 ; k<n;k++){
					if(dp[i][k]=='.'){
						if(col[k]==1) {
							flag =true;
						break;
						}
					}
				}
				if(flag) continue;
			}
		}
		if (col[i] == mini) count_c++;
	}
	// displayVector<int,string> (row,"row");
	// displayVector<int,string> (col,"col");
	if(mini == ext || mini == 0 ){
		cout<<"Case #"<<head<<": "<<"Impossible \n";
	}else
	cout<<"Case #"<<head<<": "<<mini<<" "<<count_c+count_r<<"\n";

}

int main()
{	
    fastio

    int n = 5;
	int arr[] = {1,2,3,4,5};
	ll tot = pow(2,5);
	REP(i,tot){
		int val = i+1;
		REP(j,n){
			if(val & (1<<j)) cout<<arr[j]<<" ";
		}
		cout<<'\n';
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