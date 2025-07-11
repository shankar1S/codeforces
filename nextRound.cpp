#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n); // reserve space for n elements

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int res = 0;
    int threshold = arr[k - 1]; // k-th participant's score (1-based index)

    for (int i = 0; i < n; i++) {
        if (arr[i] >= threshold && arr[i] > 0) {
            res++;
        }
    }

    cout << res << endl; // print the result
    return 0;
}
