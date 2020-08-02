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
<<<<<<< HEAD:competitiveCoding/algorithms.txt

=======
struct P
  { int x,y; 
    bool operator<(const & P &p){
      if (x != p.x) return x < p.x; // sort by sec
      else return y < p.y;  //sort by sec
    } 
    
  };


void displayVector(vi var){
      cout<<"\n output \n";
      for (auto a: var)
      {
        cout<<a<<" ";
      }
      cout<<"\n";
    }
>>>>>>> refs/remotes/origin/master:competitiveCoding/algorithms.cpp

void run(){
    ll n ,maxy =-8;
    cin>>n;
    vll v(n);
    REP(i,n) cin>>v[i];
      
}

ll main()
{	
    fastio

    int t =1;
	cin>>t;
	while(t--){
    run();
  }
	return 0;
}



//------------------ input/print array ---------------------
    
std::vector<int> v(n);
for (int i = 0; i < n; ++i) cin>>v[i];

//============================================================

  // set exact precision
  const auto prev_round = std::fegetround();
  std::fesetround(FE_DOWNWARD);
  cout<<setprecision(6)<<fixed<<val<<el;

// --------------------time a fucntion ---------------------

void timeit(){
  auto start = high_resolution_clock::now();

  cout<<power(2,30);

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop-start);
  cout<<"Time taken ->"<<duration.count()<<" ms\n";
}


// Find Maximum sum of contiguous array elements Kadane

  int Kadane(int arr[], int n) 
  { 
    int max_so_far = a[0]; 
     int curr_max = a[0]; 
    
     for (int i = 1; i < size; i++) 
     { 
          curr_max = max(a[i], curr_max+a[i]); 
          max_so_far = max(max_so_far, curr_max); 
     } 
     return max_so_far; 
  } 



// --------------find solution of a equation ---------

  ll eq(int a){

  // this is the equation
  return a*(a-1)/2;

  }

  ll solveX(int x){
  // cout<<"x:"<<x<<" ";
  ll a=0,b= 10000,mid,eval;
    while(a<b){

      mid = (a+b)/2;
      // cout<<"mid:"<<mid;
      eval = eq(mid);
      if( eval == x) return mid;

      if(eval < x){ a = mid+1;
  // cout<<"eval : "<<eval<<"\n";
  }

      if(eval > x){ b = mid-1;
      }
      // cout<<"a: "<<a<<" b:"<<b<<"\n";
    }

    return mid;
   }

 
-------------------------------------- links ----------------------------
// BIt manipulation links
https://www.cprogramming.com/tutorial/bitwise_operators.html
// builtin functions
https://www.hscripts.com/tutorials/cpp/cpp-predefined-functions.php
// coding tricks
http://codeforces.com/blog/entry/15643


----------------------------map----------------------
#include <set>

int main(){

    typedef pair<int, int> pairs; //creating pair as default data type 
    pairs p[5]; //array of pair objects
    for (int i =0; i<5; i++){
        p[i].first= (i+1)*10; //inserting first element of pair
        p[i].second = (i+1); //inserting second element of pair
    }
    set<pairs> s;   //set to sort pair
    set<pairs> :: iterator it; //iterator to manipulate set

    for (int i =0; i<5; i++){
        s.insert(p[i]); //inserting pair object in set
    }

    for (it = s.begin(); it!=s.end(); it++){
        pairs m = *it; // returns pair to m

    cout<<m.first<<" "<<m.second<<endl; //showing pair elements
    }
    return 0;
}



// -----------Number of ways to get 'T' from sum of numbers with power 'power'----
int ps(int currSum, int power ,int number, int lim, int t){
    int sum =0;
    currSum += pow(number,power);

    if (t==currSum)
        {  
            return 1;
        }
    if (t < currSum)
    {
        return 0;
    }
    for (int i = number+1; i <= lim ; ++i)
    {
        sum += ps(currSum, power , i ,lim,t);
    }
    return sum;
}


---------------------------------------------
// C++ implementation to print the longest common substring
#include <iostream>
#include <string.h>
#include <stdlib.h>
 
using namespace std;
 
/* function to find and print the longest common 
   substring of X[0..m-1] and Y[0..n-1] */
void printLCSubStr(char* X, char* Y, int m, int n)
{
    // Create a table to store lengths of longest common
    // suffixes of substrings.   Note that LCSuff[i][j]
    // contains length of longest common suffix of X[0..i-1]
    // and Y[0..j-1]. The first row and first column entries
    // have no logical meaning, they are used only for
    // simplicity of program
    int LCSuff[m + 1][n + 1];
 
    // To store length of the longest common substring
    int len = 0;
 
    // To store the index of the cell which contains the 
    // maximum value. This cell's index helps in building 
    // up the longest common substring from right to left.
    int row, col;
 
    /* Following steps build LCSuff[m+1][n+1] in bottom
       up fashion. */
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;
 
            else if (X[i - 1] == Y[j - 1]) {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                if (len < LCSuff[i][j]) {
                    len = LCSuff[i][j];
                    row = i;
                    col = j;
                }
            } else
                LCSuff[i][j] = 0;
        }
    }
 
    // if true, then no common substring exists
    if (len == 0) {
        cout << "No Common Substring";
        return;
    }
 
    // allocate space for the longest common substring
    char* resultStr = (char*)malloc((len + 1) * sizeof(char));
    resultStr[len] = '&#092;&#048;';
 
    // traverse up diagonally form the (row, col) cell
    // until LCSuff[row][col] != 0
    while (LCSuff[row][col] != 0) {
        resultStr[--len] = X[row - 1]; // or Y[col-1]
 
        // move diagonally up to previous cell
        row--;
        col--;
    }
 
    // required longest common substring
    cout << resultStr;
}
 
/* Driver program to test above function */
int main()
{
    char X[] = "OldSite:GeeksforGeeks.org";
    char Y[] = "NewSite:GeeksQuiz.com";
 
    int m = strlen(X);
    int n = strlen(Y);
 
    printLCSubStr(X, Y, m, n);
    return 0;
}

----------------------------------------------------------------------


// dynamic programming

			// factorial
int fact(int n)
	
	    if (n==0){
	        return 1;
	    }
	    if(f[n]!=-1)		//initially initialise all
	    {					//values to -1
	        return f[n];
	    }
		f[n]=(fact(n-1)*n; //make f[n] as global 
	return f[n]%5100000007;
  



unordered_set<int> isprime(int n) 
{ 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
    unordered_set<int> v;
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*2; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          v.insert(p);
return v;
} 
--------------------------------------------------------------------------
struct Node 
{
  int data;
  struct Node *next;
};
 

int main()
{
  struct Node* head = NULL;
  struct Node* second = NULL;
  struct Node* third = NULL;
   
  // allocate 3 nodes in the heap  
  head = (struct Node*)malloc(sizeof(struct Node)); 
  second = (struct Node*)malloc(sizeof(struct Node));
  third = (struct Node*)malloc(sizeof(struct Node));
 
  /* Three blocks have been allocated  dynamically. 
     We have pointers to these three blocks as first,
     second and third     
       head           second           third
        |                |               |
        ]|                |               |
    +---+-----+     +----+----+     +----+----+
    | #  | #  |     | #  | #  |     |  # |  # |
    +---+-----+     +----+----+     +----+----+
    
   # represents any random value.
   Data is random because we haven’t assigned 
   anything yet  */
   
  head->data = 1; //assign data in first node
  head->next = second; // Link first node with 
     
 
  return 0;
}
-------------------------------------------------------------------------

python

rez = [[m[j][i] for j in range(len(m))] for i in range(len(m[0]))]

transpose  

----------------- important functions ----------

"convert number from integer to binary in vector fromat output"
vi int2bin(ll a){
  vi v;
  int size = 32;
  if(a==0) {
    while(v.size() < size){
    v.eb(0);
  }
    return v;
  }
  while(a>0){
    v.eb(a&1);
    a>>=1;
  }
  while(v.size() < size){
    v.eb(0);
  }
  return v;
}

<<<<<<< HEAD:competitiveCoding/algorithms.txt

// =============== " convert number to vector " =============

vi int2vec(ll a){
  vi v;
  while(a){
    v.eb(a%10);
    a/=10;
  }
  reverse(begin(v),end(v));

  return v;
}




=======
int bin2int(std::vector<int> v){
  int num = 0;
  for (int i = 0; i < v.size(); ++i)
    num += v[i]+num*10;
  return num;
}

>>>>>>> refs/remotes/origin/master:competitiveCoding/algorithms.cpp
// binary representation of a given number
void bin(unsigned n) 
{ 
    if (n > 1) 
    bin(n>>1); 
      
    printf("%d", n & 1); 
} 




-------------- Binary search ---------------

 int binarySearch(int[] a, int n, int item)
 {  
    int low = 0;
    int high = n - 1;
    while(low<=high){
    {
      int mid = (low + high)/2;
      if (a[mid] == item) return mid;
      else if (a[mid] < item) low = mid + 1;
      else high = mid - 1;
    } 
    return -1;
 }

// alternative trick for binary search
 
auto low = lower_bound(ALL(v),element);
int pos = low - v.begin();



ll bsearch(std::vector<tuple<int,int> > &v,ll low, ll high, ll value){


  while(low <= high){
  int mid = (low+high)/2;

  if(get<0>(v[mid]) == value) return mid;
  if(get<0>(v[mid]) < value) low = mid+1 ;
  else high = mid;


  }
  return low;


  }


 -----------------------------------