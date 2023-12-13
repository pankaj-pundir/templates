#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canBe(long long h, vector<long long> &arr, long long x){
    long long water=0LL;
    for(long long i=0; i<arr.size(); i++){
        if(arr[i]<h){
            water += h-arr[i];
        }
        else 
        break;
    }
    return water<=x;
}

int main() {
	// your code goes here
	long long t;
	cin>>t;
	while(t--){
	    long long x,n, input;
	    cin>>n>>x;
        vector<long long> arr;
        for(long long i=0; i<n; i++){
	        cin>>input;
	        arr.push_back(input);
	    }
	    sort(arr.begin(), arr.end());
	    
	    long long left = arr[0], right = x + arr[n-1];
	    
	    while(left <= right ){
	        long long mid = (right+left)/2;
	        if(canBe(mid, arr, x)){
	            left = mid +1;
	        }
	        else {
	            right = mid-1;
	        }
	    }
	    cout<<right<<endl;
	    
	}
	return 0;
}