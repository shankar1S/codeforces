#include<iostream>
#include<string>
using namespace std;

int main(){
    int n,X=0;
    cin >> n;
    string op;
    while(n--){
        cin>>op;
        if(op.find('+') != string::npos){
            X++;            
        }else{
            X--;
        }
    }
    cout <<  X << endl;
    return 0;
}