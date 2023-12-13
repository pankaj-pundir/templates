#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long calc(vector<long long>& arr, long long h) {
    long long count = 0;
    for (long long i : arr) {
        count += max(0LL, h - i);
    }
    return count;
}

long long binary_search(vector<long long>& arr, long long low, long long high, long long x) {
    long long mid = 0;
    while (low <= high) {
        mid = (high + low) / 2;
        if (calc(arr, mid) < x) {
            low = mid + 1;
        }
        else if (calc(arr, mid) > x) {
            high = mid - 1;
        }
        else {
            return mid;
        }
    }
    return high;
}

long long run() {
    long long n, x;
    cin >> n >> x;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long res = binary_search(arr, min(*min_element(arr.begin(), arr.end()), x), x + *max_element(arr.begin(), arr.end()), x);
    return max(1LL, res);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    long long t;
    cin >> t;
    while (t--) {
        cout << run() << endl;
    }
    return 0;
}