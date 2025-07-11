#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n / 2; i++) {
        if (arr[i] != arr[n - 1 - i]) {
            return false;
        }
    }
    return true;
}

map<vector<int>, bool> memo;

bool canMakePalindrome(vector<int> arr, int k) {
    // Check if current array is already a palindrome
    if (isPalindrome(arr)) {
        return true;
    }
    
    // Check memoization
    if (memo.find(arr) != memo.end()) {
        return memo[arr];
    }
    
    int n = arr.size();
    
    // If array is too small to perform any operation
    if (n < k) {
        return memo[arr] = false;
    }
    
    // Try all possible subarrays of length >= k
    for (int l = 0; l < n; l++) {
        for (int r = l + k - 1; r < n; r++) {
            // Extract subarray from l to r
            vector<int> subarray;
            for (int i = l; i <= r; i++) {
                subarray.push_back(arr[i]);
            }
            
            // Sort to find k-th smallest
            sort(subarray.begin(), subarray.end());
            int kthSmallest = subarray[k - 1];
            
            // Find all indices in range [l, r] that have value kthSmallest
            vector<int> candidates;
            for (int i = l; i <= r; i++) {
                if (arr[i] == kthSmallest) {
                    candidates.push_back(i);
                }
            }
            
            // Try removing each candidate
            for (int idx : candidates) {
                vector<int> newArr;
                for (int i = 0; i < n; i++) {
                    if (i != idx) {
                        newArr.push_back(arr[i]);
                    }
                }
                
                if (canMakePalindrome(newArr, k)) {
                    return memo[arr] = true;
                }
            }
        }
    }
    
    return memo[arr] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        memo.clear();
        
        if (canMakePalindrome(arr, k)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}