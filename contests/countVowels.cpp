#include<iostream>
using namespace std;
int main(){
    string s;
    getline(cin, s);
    int cnt =0;
    for(char c : s){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
            cnt++;
        }

    }
    return cout << cnt << endl, 0;
}