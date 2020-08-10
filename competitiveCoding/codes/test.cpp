
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

  // sum the numbers
//   template<class T>
//       auto sum(T a) {return a;}
//   template<typename T, typename... Args>
//   auto sum(T a, Args... args) { return a + sum(args...); }

  // display all the content 
//   template<class T>
//   void print(T a){
//       cout<<a<<"\n";
//       }
//   template<typename T,typename... types>
//   void print(const T& a,const types& ... args){
//     cout<<a<<",";
//     print(args...);
//       }

  // vector print template

//   template<typename T1,typename T2>ostream& operator<<(ostream& os,pair<T1,T2> ptt){
//       os<<ptt.first<<","<<ptt.second;
//       return os;
//       }


//   template<typename T>ostream& operator<<(ostream& os,vector<T> vt){
//   os<<"{";    for(auto i:vt)
//           os<<i<<","; os<<"}"; return os;
//   }


// ******************* useful functions *******************

inline double log(ll a,ll b){
    return log10(a)/log10(b);
}


// ***************************** Code ***********************

// struct P
//   { int x,y; 
//     bool operator<(const & P &p){
//       if (x != p.x) return x < p.x; // sort by sec
//       else return y < p.y;  //sort by sec
//     } 
    
//   };


void displayVector(vi var){
      cout<<"\n output \n";
      for (auto a: var)
      {
        cout<<a<<" ";
      }
      cout<<"\n";
    }
ll sqV = -1,rec1=-1,rec2 =-1;
string eval(map<ll,ll> mapy){
    int sq = 0,rec = 0;
    sqV = -1,rec1 =-1,rec2 =-1;
    for(auto i : mapy){
        // cout<<i.F<<" "<<i.S<<"\n";
        if(i.S > 3 && !sq){
            // cout<<"in";
            sq = 4;
            i.S -= 4;
            sqV = i.F;
        }
        if(i.S > 3){
            rec = 4;
            mapy[i.F] -=4;
            rec1 = i.F;
            // rec2 = i.F;
        }
        else if(i.S > 1){
            rec +=2;
            i.S -=2;
            if(rec1 == -1)
            rec1 = i.F; 
            else   rec2 = i.F;
        }
        if(sq >= 4 && rec >=4){
            return "YES";
        }
        // cout<<i.F<<" "<<i.S<<"\n";
    }
    return "NO";
}

bool iniCheck(map<ll,ll> &mapy){

    // for(auto i : mapy){
    //     cout<<i.F<<" "<<i.S<<"\n";
    // }
    // cout<<sqV<<rec1<<rec2<<"\n";
    if(sqV == -1 || rec1 == -1 ) return false;
    if(mapy[sqV] < 4) return false;
    if(rec2 == -1 && mapy[rec1] < 4) return false;
    if(sqV == rec1 && rec2 ==-1){
        if(mapy[sqV] < 8) return false;
        return true;
    }
    else if(sqV == rec1 && mapy[sqV] + mapy[rec2] < 8) return false;
    else if(mapy[rec1] + mapy[rec2] < 4) return false;
    return true;
}

void run(){
    ll n ,k,maxy =-8;
    cin>>n>>k;
    vll v(n);
    REP(i,n) cin>>v[i];

    multiset<int> ss;
    int c,val = 0;
    ss.insert(v[0]);
    int sumy = 0;
    if(k>2){
        int counter =0;
        vector<int> dp(101,0);
        REP(i,n){
            dp[v[i]]++;
        }
        REP(i,101){
            if(dp[i]>1) counter+= dp[i];
        }
        cout<<counter+k<<"\n";
        return ;
    }
    int ans1 = 0, ans2 =0;
    FOR(i,1,n,1){

        int county = ss.count(v[i]);
        if(county == 1){
            c = val +2;
        }
        else if(county > 1) c = val+1;
        else{
            c = val;
        }
        if(k+val >= c){
            ss.insert(v[i]);
            val = c;
            // cout<<"el";
        }
        else{
            // cout<<"int"<<i<<"\n";
            sumy += val+k;
            ss.clear();
            ss.insert(v[i]);
            val = 0;
        }
        // ss.insert()
    }
    sumy += val+k;
    ans1 = sumy;
    sumy = 0;
    ss.clear();
    ss.insert(v[0]);
    val = 0;
    FOR(i,1,n,1){

        int county = ss.count(v[i]);
        if(county == 1){
            c = val +2;
        }
        else if(county > 1) c = val+1;
        else{
            c = val;
        }
        if(k+val > c){
            ss.insert(v[i]);
            val = c;
            // cout<<"el";
        }
        else{
            // cout<<"int"<<i<<"\n";
            sumy += val+k;
            ss.clear();
            ss.insert(v[i]);
            val = 0;
        }
        // ss.insert()
    }
    sumy += val+k;
    ans2 = sumy; 
    // cout<<"ans"<<ans1<<"\n";
    debug2(ans1,ans2);
    cout<<min(ans1,ans2)<<"\n";
        
    
      
}
int main()
{	
    fastio

    int t =1;
	cin>>t;
	while(t--){
    run();
  }
	return 0;
}
