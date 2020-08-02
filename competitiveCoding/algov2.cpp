#include<bits/stdc++.h>
using namespace std;

//  Dijkstra
	// ======================= Dijkstra ==================

	 // ========= getting the path ==========
	void trace(int k){if(p[k]!=-1) trace(p[k]); printf("%d ",k);}

	// ============== Dijktras algo implementation==============

	vector<vector <pair<int, int> > > g;

	// add elements in graph
	void addEdge(int a,int b,int w){
		g[a].push_back({b,w});
		g[b].push_back({a,w});
	}

	void displayLinkedGraph(){
		int cc=0;
		for(auto i : g){
			cout<<cc<<"\n";
			for(auto j: i){
				cout<<"["<<j.first<<"-"<<j.second<<"] ";
			}
			cout<<"\n";
	}


	int ss = 9;
	std::vector<int> d(ss,INT_MAX);
	bool visited[ss] = {false};
	vector <int> predecessor(ss,-1);
	int source =0 ;
	priority_queue < pair<int, int> > pq; // weight and node name 


	g.resize(ss);
	addEdge(0, 1, 4); 
	// source inputs
	pq.push({0,source});
	d[source] = 0;

	// dijktras algo
		while(!pq.empty()){
			auto u = pq.top();
			pq.pop();
			if(visited[u.second]) continue;
			visited[u.second] = true;
			// cout<<"\n node "<<u.second<<"\n";
			for(auto i:g[u.second]){

				if (d[i.first] > -1*u.first+i.second){
					d[i.first] = -1*u.first+i.second;
					predecessor[i.first] = u.second; // assign predecessor
					pq.push({-1*d[i.first],i.first});
				}	
				// cout<<"-- "<<i.first<<" "<<d[i.first]<<"\n";
			}
		}  



	// =========== codeforce best code === for dijkstra ============

	#include <bits/stdc++.h>
	#define INF 2e18

	typedef long long ll;
	typedef std::pair<ll,int> ii;

	int n,m,p[100005];
	std::vector<ii> g[100005];
	ll d[100005];
	std::priority_queue<int> q;

	// recursive code to print ehe path
	void trace(int k){if(p[k]!=-1) trace(p[k]); printf("%d ",k);}

	int main(){
		scanf("%d%d",&n,&m);

		while(m--){
			int u,v,l;scanf("%d%d%d",&u,&v,&l);
			//  inserting the elements
			g[u].push_back(ii(l,v)); g[v].push_back(ii(l,u));
		}
		
		std::fill(p,p+n+5,-1);std::fill(d,d+n+5,INF);
		d[1] = 0;
		q.push(1);
		while(!q.empty()){
			int u=q.top(); q.pop();
			for(ii e: g[u]){
				int v=e.second; ll t=d[u]+e.first;
				if(t<d[v]) {p[v]=u;d[v] = t;q.push(v);}
			}
		}
		if(d[n]==INF) {printf("-1\n"); return 0;}
		trace(p[n]);
		printf("%d\n",n);
		return 0;
	}

//  Fenwick Tree
	//---------------- BIT or Fenwick Tree -----------------------

	ll getSum(vl &v, int index){
	  ll sumy = 0;
	  while(index>0){
	    sumy += v[index];
	    index -= (index & (-index));
	  }
	  return sumy;
	}

	void updateBIT(vl &v,int size,int index,int value){
	  while(index <= size){
	    v[index] += value;
	    index += (index & (-index));
	  }

	}

// Segment Tree-----

	template<typename T>
	class SegmentTree{
  vector<int> tree;     // private  members
  T size;
  T vsize;
  std::vector<int> vv;
  public:

  SegmentTree(vector<int> v){ 
      // constructors
    vsize = (T) v.size();
    T x = (T) ceil(log2(vsize));
    vv = v;
    size = 2*(T)(1<<x)-1;
    tree.resize(size); // = new T[size];

    cout<<"initialized : size ->"<<v.size()<<"\n";
    constructTree(0,0,vsize-1); 
  }

  void constructTree(int node,int start,int end){
    // node the ptr to the actual values
    // start and end are the sliding windows for the tree.

    if(start==end) tree[node] = vv[start];
    else {
      int mid= (start+end)/2;
      constructTree(2*node+1, start,mid);

      constructTree(2*node+2, mid+1,end);

      tree[node] = tree[2*node+1] + tree[2*node+2];
      //  edit the operation that you want to perform within

    }
  }

  T query(int a,int b){
    if(a<0 || b>=vsize || a>b) return -1;
    return rangeQuery(0,vsize-1,a,b,0);
  }

  T rangeQuery(int l,int r,int limit_l,int limit_r,int node){
    // l -> range to be slided throughout
    // r -> range to be slided throughout
    // limit_l -> user defined fixed query
    //  limit_r -> user defined limit
    //  node -> current node
    if(limit_l <= l && limit_r >= r) return tree[node]; // exactly within the range
    if(limit_l >r || limit_r <l) return 0; // outside the range
    int mid = (l+r)/2;
    return rangeQuery(l,mid,limit_l,limit_r,2*node+1)+
    rangeQuery(mid+1,r,limit_l,limit_r,2*node+2);
  }

  void displayTree(){
    cout<<"segment tree\n";
    for(auto i:tree){
      cout<<i<<" ";
    }
    cout<<"\n";
  }};



// ----------------- Convert array to min difference ---------

void convertMIN(vl &v){
  // create a copy of v
  vl x(ALL(v));
  sort(ALL(x));
  // remove the differences to _minimal
  REP(i,v.size()){
    v[i] = lower_bound(ALL(x),v[i]) - x.begin() + 1;
  }
  //  original array updated
}

// --------------- cyclic prefix sum ---------

    ll getSum(int l,int r)
    {
        if(l<=r)
        {
            return prefix[r]-(l==0?0:prefix[l-1]);
        }
     
        return prefix[n-1]-prefix[l-1]+prefix[r];
    }

// Chain matrix multiplication

 // --------------- chain matrix multiplication - upper triangle --------
    for(int size=2;size<=n;size++)
            {
                for(int i=0;i<n;i++)
                {
                   int l=i,r=(i+size-1)%n;
     
                   for(int j=l;j!=r;j=(j+1)%n)
                   {
                       dp[l][r]=min(dp[l][r],dp[l][j]+dp[(j+1)%n][r]+getSum(l,r));
                   }
                }
            }

// Bits representaion of number  
	// -------------- Calculate number of ones bits in a number ---------


	int calcbits(int a){
	    int count = 0;
	    while(a){
	        if(a&1) count++;
	        a = a>>1;
	    }
	    return count;
	}

	// ------------- provide array of bits representaion of a number ----------
	//  32 bit size number
	void calcbits(int *arr,int a){
	    int i =0;
	    while(i<32){
	      if(a&1) arr[i]=1;
	      else arr[i]=0;
	      if(a)
	      a = a>>1;
	      i++;
	    }
	}

// Prime operations 

	int checkPrimeNumber(int n)
	{
	  bool flag = false;

	  for(int i = 2; i*i <= n; ++i)
	  {
	      if(n%i == 0)
	      {
	          flag = true;
	          break;
	      }
	  }
	  return flag;
	}

	// ====================== find the prime factors ==================

	vi primeFactors(int n)  
	{  
	  // return vector of prime factors of the number
	    set<int> s;

	    while (n % 2 == 0)  
	    {  
	        s.insert(2);
	        n = n/2;  
	    }  
	    for (int i = 3; i <= ceil(sqrt(n)); i = i + 2)  
	    {   
	        while (n % i == 0)  
	        {  
	            s.insert(i); 
	            n = n/i;  
	        } 
	    }  
	    if (n > 2)  
	        s.insert(n);

	    std::vector<int> v(s.begin(),s.end());
	    return v;
	} 

	// ============= all prime number below n [Seives algo] ============

	std::vector<int>  primeSeives(int n)  
	{  
	  std::vector<bool> mark(n,true);
	  for(int i=2; i*i <=n ; i++){
	    if(!mark[i]) continue;
	    for(int j=i*i; j<=n; j+=i){
	      mark[j] = false;
	    }
	  }
	  std::vector<int> v;
	  for (int i = 2; i <=n ; ++i)
	  {
	    if(mark[i]) v.push_back(i);
	  }

	  return v;
	} 

<<<<<<< HEAD
	// ----------- vectors of prime till n ------------

	#define L 1e6
	std::vector< std::vector <int> > factors(L+1);


	void generateFactors(){
	    for(int i=1; i<=1000;i++){
	        for(int j =1; j<1e6+1 && i*j <= 1e6; j++){
	            factors[i*j].eb(i);
	            if(i!=j)
	            factors[i*j].eb(j);
	        }
	    }
	}
	void sorty(){
	    REP(i,L+1){
	        sort(ALL(factors[i]));
	    }
	}

	void printfactors(){
	    FOR(i,1e6-20,1e6,1){
	            cout<<"\n"<<i+1<<"\n";
	        for(auto j:factors[i+1]){
	            cout<<j<<" ";
	        }

	    }
	}
=======
	// ==== last prime using seives ======

	void LastPrimeSieve()
	{
	    lp[1]=1,lp[0]=0;
	    for(ll i=2; i<=1000000; i++)
	    {
	        if(lp[i]==0)
	        {
	            lp[i]=i;
	            for(ll j=i*i; j<=1000000; j+=i)
	            {
	                if(lp[j]==0)
	                {
	                    lp[j]=i;
	                }
	            }
	        }
	    }
	}

>>>>>>> refs/remotes/origin/master

// power with mod
	//-------  fast exponention 2k ary method ------------------


	ll BinPow(ll a,ll b,ll m){
    ll ans = 1;
    while(b){
        if(b & 1)ans = ans *1ll* a % m;
        a = a *1ll* a % m;
        b >>= 1;
    }
    return ans;
	}

// Combination with mod 
	// ------------ combination and factorial ---------
	int fact(int n) 
	{ 
	    int res = 1; 
	    for (int i = 2; i <= n; i++) 
	        res = res * i; 
	    return res; 
	} 

	int nCr(int n, int r) 
	{ 
	    return fact(n) / (fact(r) * fact(n - r)); 
	} 

// Search map and set

	bool findMap(map<int,int> &c,int p){
	if(c.find(p) == c.end()) return false;
	return true;
	}

	bool findSet(map<pair <int,int> ,int> &c,pair<int,int> p){
	if(c.find(p) == c.end()) return false;
	return true;}

// Count number of factors

	ll count_factors(ll a){
    ll count = 0;
    if(a==1) return 1;
    for(int i=1;i*i<=a;i++){
        if(a%i==0){
            count++;
            if(a/i != i) count++;
        }
    }
    return count;
	}

// Trie 
	
	struct Trie
	{
	    Trie *children[26];
	    bool isEnd;
	};

	Trie *TrieGetNode(){
	    Trie *node = new Trie;
	    for (int i = 0; i < 26; ++i)
	        node->children[i] = NULL;
	    node -> isEnd = false; 
	    return node;
	}

	void TrieInsert(Trie *root, string s){
	    int ptr =0 ,loc;
	    for (int i = 0; i < s.length(); ++i)
	    {   loc = s[i] - 'a';
	        if(!root->children[loc]) root->children[loc] = TrieGetNode();
	        root = root->children[loc];
	    }
	    root ->isEnd = true;
	}


	bool recursiveSearch(Trie *root,Trie *node,int ptr, string s){
	    if(ptr == s.length() && node->isEnd ) { return true;}
	    int loc = s[ptr] - 'a';
	    if(node->children[loc] != NULL){
	        if(node->children[loc]->isEnd)
	            {
	                return recursiveSearch(root,node->children[loc], ptr+1,s) || recursiveSearch(root,root,ptr+1,s);
	        }
	        return recursiveSearch(root,node->children[loc],ptr+1,s);
	    }
	    return false;

	}


// -------------- Extended euclidean algo -------------------
	//  ------------- calulating the bezots constants ---------------
def egcd(a, b):
    x,y, u,v = 0,1, 1,0
    while a != 0:
        q, r = b//a, b%a
        m, n = x-u*q, y-v*q
        b,a, x,y, u,v = a,r, u,v, m,n
    gcd = b
    return gcd, x, y

print(egcd(102,38))
