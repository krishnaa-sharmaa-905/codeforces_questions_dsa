#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;



void solve() {
    int x,y,z;
    cin>>x>>y>>z;
    
    int a = 0, b = 0, c = 0;
    bool possible = true;
    for(int i = 0;i<32;i++){
        int bx = (x>>i)&1;
        int by = (y>>i)&1;
        int bz = (z>>i)&1;
        bool found = false;
        for(int ba:{0,1}){
           for(int bb:{0,1}){
                for(int bc:{0,1}){
                    if ((ba & bb) == bx && (bb & bc) == by && (bc & ba) == bz) {
                       found = true;
                        a |= (ba<<i);
                        b |= (bb<<i);
                        c |= (bc<<i);
                        break;
                    }

                }
                if(found) break;
            }
            if(found) break;
        }
        if(!found){
            possible = false;
            break;
        } 

    }
    if(possible){
        cout<<"YES\n";
    }
        
    else{
        cout<<"NO\n";
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}