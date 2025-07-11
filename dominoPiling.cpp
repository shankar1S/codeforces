#include<iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int inputProduct = m * n;
    if(inputProduct % 2 ==0){
        cout << (inputProduct / 2) << endl;
    } else {
        cout << (inputProduct - 1) / 2 << endl;
    }
}