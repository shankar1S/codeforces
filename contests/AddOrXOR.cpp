#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        long long a,b,x,y;
        cin >> a >> b >> x >> y;
        
        if (a == b) { 
            cout << 0 << '\n';
            continue;
        }
        if(a < b){
            long long diff = b-a;
            long long c0 = min(x,y);
            long long c1 = x;
            
            long long even_cnt, odd_cnt;
            if(a%2 == 0){
                even_cnt = (diff + 1)/2;
            }else{
                even_cnt = diff/2;
            }
            odd_cnt = diff - even_cnt;
            
            long long cost = even_cnt * c0 + odd_cnt * c1;
            cout << cost << '\n';
            continue;
        }
        
        if(a%2 == 0){
            cout << -1 << '\n';
            continue;
        }
        long long cost = y;
        long long a1 = a-1;
        
        if(b == a1){
            cout << cost << '\n';
            continue;
        }
        
        long long diff = b-a1;
        long long c0 = min(x,y);
        long long c1 = x;
        
        long long even_cnt = (diff + 1) / 2;   // start is even
        long long odd_cnt  = diff - even_cnt;

        cost += even_cnt * c0 + odd_cnt * c1;
        cout << cost << '\n';
    }
    return 0;
}










