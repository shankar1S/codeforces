#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort(arr, arr + n);
        int min_val = arr[0];
        int max_val = arr[n - 1];

        int dist1 = abs(s - min_val) + (max_val - min_val);
        int dist2 = abs(s - max_val) + (max_val - min_val);

        cout << min(dist1, dist2) << endl;
    }
    return 0;
}
