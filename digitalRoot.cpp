#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll k; int x;
        cin >> k >> x;
        cout << x + 9LL * (k - 1) << endl; //All numbers with digital root x are of the form:x, x + 9, x + 18, x + 27, ...
         // 9LL ensures multiplication is done using 64-bit arithmetic
    }
    return 0;
}
