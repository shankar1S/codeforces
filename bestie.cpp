// *Not Yet Completed*

#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int i) {
    if( a == 0) return i;
    return gcd(i % a, a);
}   

int findGCD(int arr[]) {

}

int main() {
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        if (n == 1) {

        }
        int arr[n];
        for(int i =0; i<n; i++){
            cin >>  arr[i];
        }
        cout<< findGCD(arr) << endl;
    }

}