#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;
typedef long long ll;
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

long long lcm(int a, int b) {
    return (1LL * a / gcd(a, b)) * b;
}

void solve() {
    int n;
        cin>>n;
        vector<ll> b(n);
        unordered_map<int,vector<ll>> mpp;
        for(int i = 0;i<n;i++){
            cin>>b[i];
            mpp[b[i]].push_back(i);
        } 
        vector<ll> ans(n,0);
        // ll sum = 1LL*accumulate(b.begin(),b.end(),0);
        // ll sum = 0;
        ll diff = 0;
        for(auto it: mpp){
            if(it.second.size()%it.first!=0){
                cout<<-1<<endl;
                return;
            }
            diff += it.second.size()/it.first;
        }
        // cout<<diff<<endl;
        if(diff>n) {
            cout<<-1<<endl;
            return;
        }
        int j =  1;
        for(auto it: mpp){
            vector<ll> temp = it.second;
            int k = it.first;
            int i = 0;
            ll currdiff = temp.size()/k;
            
            while(i<temp.size()){
                ll cnt = k;
                // if(currdiff==1) 
                // currdiff *= k;
                // cout<<"test for: "<<k<<" "<<currdiff<<" ";
                while(cnt--){
                    ans[temp[i]] = j;
                    i++;
                }
                j++;
            }
        }
        
// cout<<endl<<"ans: ";
        for(int i = 0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
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