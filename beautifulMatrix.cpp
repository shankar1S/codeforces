#include<bits/stdc++.h>
using namespace std;

int main(){
    /*
    int matrix[5][5];
    int row, col;

    for(int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> matrix[i][j];
            if( matrix[i][j] == 1){
                row = i;
                col = j;
            }
        }
    }

    int moves = abs(row - 2) + abs(col - 2);
    cout << moves << endl;*/

    int x;
    for(int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> x;
            if(x == 1) {
                int moves = abs(i-2) + abs(j-2);
                cout << moves << endl;
                return 0;
            }
        }
    }
}