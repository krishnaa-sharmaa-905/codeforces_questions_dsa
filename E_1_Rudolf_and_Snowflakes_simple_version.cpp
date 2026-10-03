#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<bool> possible(1e6 +1 ,false);

void check(){
    for(int k = 2;k<10000;k++){
        ll curr = 1 + k + k*k;

        ll power = k*k;
        while(curr<=1e6){
            possible[curr] = true;
            if (power > 1e6 / k) break;
            power = power*k;
            curr += power;
        }
    }
}

void solve() {
    int n;
    cin>>n;
    
    if(possible[n]){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    check();
    while (t--) {
        solve();
    }
    return 0;
}