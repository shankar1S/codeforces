#include <bits/stdc++.h>
using namespace std;

vector<int> buildSufArr(string &s) {
    int n = s.length();
    vector<int> sufArr(n);
    vector<string> suf(n);

    // Generating all the suffixes
    for (int i = 0; i < n; i++)
        suf[i] = s.substr(i);
    

    // Sort all suffixes alphabetically
    sort(suf.begin(), suf.end());

    // Create the suffix array using the starting position of all the suffixes by subtracting it from the length of the original string
    for (int i = 0; i < n; i++)
        sufArr[i] = n - suf[i].length();

    return sufArr;
}

int main() {
    string s ;
    cin >> s;
    vector<int> sufArr = buildSufArr(s);

    for (int i : sufArr)
        cout << i << " ";

    return 0;
}
