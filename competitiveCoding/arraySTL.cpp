// ----------------  Array -----------------



// longest common subseuence problem ---------------------
int lcs( string &X, string &Y, int m, int n ) 
{ 
   int L[m+1][n+1]; 
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

// ------------- Sort -------------


// `Sort by only by second element`;

bool sortbysec(const tuple<int, int, int>& a,  
               const tuple<int, int, int>& b) 
{ 
    return (get<1>(a) < get<1>(b)); 
    // change sign to sort it with decreasing order
} 
sort(v.begin(), v.end(), sortbysec); 

// two elements in increasing order of 2nd element

bool sortbysec(const tuple<int, int>& a,  
               const tuple<int, int>& b) 
{ 
    return (get<1>(a) < get<1>(b)); 
} 

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



