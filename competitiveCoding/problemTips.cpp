// Famous problems

// N queens problem
	use backtracking
		use array flags for column and row and diagonal (both)
		to check there is another conflict or not

// Greedy algo
	
	// coin problem
	Select the maximum Greedily

	// Scheduling
	use the earliest deadline first approach

	// minimising the sum
	min(|a1-x|^c+|a2-x|^c...)   find x ...
	x  = median of the array  for c =1
	x  = avg. of the array  for c = 2

	// compression - huffmann coding

// Dynamic programming

	HAve correctness of complete search and efficiency of Greedy search
	two major uses 
		- counting number of soln
		- finding the optimal soln

	// coin problem 
		//a. with given coin make the sum x with few coin possible

		min ( solve(x-c)+1 )  [c belongs to all coins value]

		val[0] = 0
		FOR(x,1,n,1){
			val[x] = INF; 
			for(auto c: coins){
				if(x-c > 0) val[x] = min(val[x-c]+1,val[x]);
			}
		}
		val[<the element you want>];
		// if also want to construct the combination use a vector to store the previous element for current one.


		// b. count number of solutions possible to make x. with given coin frequency.


		count[0] = 0
		FOR(x,1,n,1){
			count[x] = INF; 
			for(auto c: coins){
				if(x-c > 0) count[x] += count[x-c];
			}
		}

	// Longest inc. subsequence

		O(n^2) approach -- general one
		O(nlogn) find it 

	// maxmize the sum of path in grid (down and right movement allowed) 

		sum(x,y) = max(sum(x-1,y),sum(x,y-1))+val[x][y];

	// Knapsack problem

		Fixed Knapsack create a sum using the given values. Use matrix 
		ans[n][m] = min(ans[n-1][m-w]) where 'w' belongs to the 'array'

	// Edit distance Levenshtein Distance
		1. insert 2. remove 3. modify  these operations to make two stings same
		2D matrix with '0' rows available

		Dist(a,b) = min(Dist(a,b-1)+1,Dist(a-1,b)+1,Dist(a-1,b-1)) + cost(a,b) 
		cost(a,b) == 0 if a==b else 1

	// Two pointer Method
		1. Subarray sum
			-- start both from left and move forward
		2. 2Sum method  
			-- sort the array
			-- start from left and right simulataneously and converge the range

	// Nearest Smallest element
		-- Use stack
		-- push the element until smaller than top is found
		-- pop the element until smaller element is encounter or stack is empty

	// Sliding window minimum
		-- Use queue
		-- keep track of of number location and the minimum is in front

// Range Queries