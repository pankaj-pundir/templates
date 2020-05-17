// Key findings & observations

// polynomial time complexity means the algo is efficient
// NP hard problem is set of problems where no set of polynomial algo is known


// complete search is generating all possible outcome and searching the best one from it
// pruning the search is stopping at the partial ans where the result is not possible (adding intelligence to the algo)

vector<map<int,int>::value_type > vv(um.begin(),um.end()); // copy map elements in vector
	// vv[i].first; vv[i].second


make_heap(v1.begin(), v1.end());  //make heap
v1.front() // maximum element of the heap
push_heap(v1.begin(), v1.end()); // reoreder the heap
pop_heap(v1.begin(), v1.end()); 
v1.pop_back(); 
      
next_permutation(ALL(v)); // generates next permutation in increasing order

// when comes to grouping think about SORTING
// Default values of map is 0, if not initialized

                  | map             | unordered_map
---------------------------------------------------------
Ordering        | increasing  order   | no ordering

Implementation  | Self balancing BST  | Hash Table
                | like Red-Black Tree |  

search time     | log(n)              | O(1) -> Average 
                |                     | O(n) -> Worst Case

Insertion time  | log(n) + Rebalance  | Same as search
                      
Deletion time   | log(n) + Rebalance  | Same as search

//  while traversing stack used while loop
//  maps cannot be accesed using indexes

ListNode* middleNode(ListNode* head) {
        ListNode* th = head;
        while(th->next != NULL){
            th = th->next;
            head = head->next;
            if(th->next != NULL){
                th = th->next;
            }
        } 
        return head;
    }



################  Custom Stack  ###############
 class MinStack {
	public:
	    stack<int> st;
	    stack<int> mini;
	    MinStack() {

	    }
	    void push(int x) {
	        this->st.push(x);
	        if(mini.size() == 0){
	            this->mini.push(x);   
	        }
	        else
	        this->mini.push(min(x,this->mini.top()));
	    }
	    void pop() {
	        
	        if(this->st.size()!=0)
	        {
	            this->st.pop();
	    }
	    }
	    int top() {
	        return this->st.top();
	    }
	    int getMin() {
	        return this->mini.top();
	    }
	};

//  inline functions write the function were the function is invoked, optimization technique


//  Valid paranthesis string 
def checkValidString(self, s):
        lo = hi = 0
        for c in s:
            lo += 1 if c == '(' else -1
            hi += 1 if c != ')' else -1
            if hi < 0: break
            lo = max(lo, 0)

        return lo == 0