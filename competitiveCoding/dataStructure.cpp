// ---------------- Data Structures-----------------


// vector
std::vector<tuple<int,int,int> > v, w(10,5),z(ALL(w)); //ALL() w.begin(),w.end()
v.push_back({1,2,5}); v.emblce_back(3);  //insert elements
v.size();   // size
v[3]; v.back();

// string
string s = "pankaj";
string h = s.substr(2,3); // "nka"


// set
set<int> s;   // sorted form
unordered_set <int> s;   // faster 
multiset<int> s;   //multiple elements allowed
s.insert(3);
s.count(3); // check the element is present
s.find(3);  //return an iterator

// map
map<string, int> m;
unordered_map <string, vector<int> > um;
m["monkey"] = 4; //setting an element
m["monkey"]; // accessing the element
for(auto k :m) k.first; k.second; // elements access


// bitset   -- less memory
bitset<10> b, a(string("001010110"));  // value can be 0 or 1
b.count(); // returns number of 1 in the bitset
a&b; a|b; a^b; // and or xor

// deque   -- can be changed from both sides of the array
deque<int> d;  // slower than the vector due to complex implementation
d.push_back(3);  d.pop_back(5);
d.push_front(4); d.pop_front(4);

// queue -- add back remove front
queue<int> q;
q.push(2);
q.front();
q.pop();

// priority Queue   insertion and removal O(logn)  retrieval o(1)
// implemented using a heap struucture rather than balanced binary tree (ordered set)
priority_queue<int> pq; // decreasing order
pq.push(3);
pq.top();
pq.pop();
priority_queue<int, std::vector<int> ,greater<int> > pq; // finding and reamoving smallest element


// stack 
stack<int> s;
s.push(2);
s.top();
s.pop(); 


// common functions
reverse(ALL(v));
sort(ALL(v));
random_shuffle(ALL(v));

v.lower_bound(x); // find the element less than x in v
v.upper_bound(x); // find the element greater than x in v
auto ind = lower_bound(v.begin(),v.end(),value) - v;
v[ind]; // the loc 


// Fenwick Tree

class FenwickTree
{
    std::vector<int> v;
    int size = 0;
    public:
    FenwickTree(std::vector<int> &v_new){
        size = v_new.size();
        v.resize(size);
        for (int i = 0; i <= size; ++i)
            update(i,v_new[i]);
        // cout<<" Fenwick Tree Created Indexing with 1 \n";
    }
    
    ll getSum( int index){
      ll sumy = 0;
      while(index>0){
        sumy += v[index];
        index = (index & (index+1))-1;
      }
      return sumy;
    }

    void update(int index,int delta){
      while(index <= size){
        v[index] += delta;
        index = index | (index+1);
      }
    }
    // ~FenwickTree();
};


// longest common subseuence problem 
    int lcs( string &X, string &Y, int m, int n ) 
    { 
       int L[m+



        1][n+1]; 
       int i, j; 
       
       /* Following steps build L[m+1][n+1] in bottom up fashion. Note  
          that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
       for (i=0; i<=m; i++) 
       { 
         for (j=0; j<=n; j++) 
         { 
           if (i == 0 || j == 0) 
             L[i][j] = 0; 
       
           else if (X[i-1] == Y[j-1]) 
             L[i][j] = L[i-1][j-1] + 1; 
       
           else
             L[i][j] = max(L[i-1][j], L[i][j-1]); 
         } 
       } 
         
       /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
       return L[m][n]; 
    } 

// comparators 
    bool sortbysec(const tuple<int, int, int>& a,  
               const tuple<int, int, int>& b) 
          { 
              return (get<1>(a) < get<1>(b)); 
              // change sign to sort it with decreasing order
          } 

// Custom Structure
  struct P
  { int x,y; 
    bool operator<(const & P &p){
      if (x != p.x) return x < p.x; // sort by sec
      else return y < p.y;  //sort by sec
    } 
    
  };


// ------------- Sort -------------



// sort 1 element ascending order for tie 2nd element in dec order

bool sortbysec(const tuple<int, int>& a,  
               const tuple<int, int>& b) 
{ 
   return ( get<1>(a) > get<1>(b) ||  ( !( get<1>(b) > get<1>(a) ) && get<0>(a) < get<0>(b) ) );
    // change sign to sort it with decreasing order
} 


// `Insertion sort`;

void insertionSort (vector<int> data, int n) 
{
int i, j, tmp;

 for (i=1; i<n; i++)
 {
     j=i;
     tmp=data[i];
     while (j>0 && tmp<data[j-1])
     {
           data[j]=data[j-1];
           j--;
     }
     data[j]=tmp;
 }
}

// `bubble sort with template`;

template <class T>
void BubbleSort(T &arr){
    	bool swapped;
    	int n  = arr.size();
    	for(int i=0;i<n-1;i++){
    		swapped=false;
    		for(int j=0;j<n-i-1;j++){
    			if(arr[j] > arr[j+1]){
    				swapped=true;
    				swap(arr[j],arr[j+1]);
    			}
    		}
    		//If no swaps occur then terminate the outer loop
    		if(!swapped)
    			break;
    	}
    	// return arr;
    }



// C++ priority queue with sorting

struct S
{
    int m_n1;
    int m_n2;
    int m_n3;

    S(int n1, int n2, int n3) : m_n1(n1), m_n2(n2), m_n3(n3)
    {
    }
    bool operator<(const struct S& other) const
    {
        //Your priority logic goes here
        if(m_n1 == other.m_n1) return m_n2 > other.m_n2;
        return m_n1 < other.m_n1;
    }
};

priority_queue<S> pq;