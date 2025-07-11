// 




#include <bits/stdc++.h>
using namespace std;

long long calculateSum(const vector<int>& arr) {
    int n = arr.size();
    long long sum = 0;
    int currentMin = arr[0];
    
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            currentMin = arr[i];
        } else {
            currentMin = min(currentMin, arr[i]);
        }
        sum += currentMin;
    }
    
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        // Calculate original sum without any operation
        long long minSum = calculateSum(arr);
        
        // Edge case: if n = 2, we can only do one operation
        if (n == 2) {
            // Try the operation: a[0] += a[1], a[1] = 0
            vector<int> temp = arr;
            temp[0] = temp[0] + temp[1];
            temp[1] = 0;
            long long newSum = calculateSum(temp);
            minSum = min(minSum, newSum);
            
            cout << minSum << "\n";
            continue;
        }
        
        // For larger arrays, we need to be more strategic
        // Key insight: we want to move larger values to earlier positions
        // to potentially reduce the prefix minimum
        
        // Try all possible operations with some optimizations
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Skip if a[j] is 0 (no benefit from moving 0)
                if (arr[j] == 0) continue;
                
                // Optimization: if we're moving to a position that's already
                // much smaller than what we're adding, it might not help
                // But we still need to check all cases for correctness
                
                // Create temporary array and perform operation
                vector<int> temp = arr;
                temp[i] = temp[i] + temp[j];
                temp[j] = 0;
                
                // Calculate new sum
                long long newSum = calculateSum(temp);
                minSum = min(minSum, newSum);
            }
        }
        
        cout << minSum << "\n";
    }
    
    return 0;
}