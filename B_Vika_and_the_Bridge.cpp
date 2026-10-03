#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

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
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    int s = 0;
    int e = n;
    int ans = n;
    while(s<=e){
        int m = s + (e-s)/2;
        bool repaint = false;
        bool possible = true;
        vector<int> diffcol;
        int i ;
        unordered_map<int,int> color;
        for(i = m;i<n ;i+=m){
            color[a[i]]++;
            if(color.size()>2){
                possible = false;
                break;
            }
        }
        for(auto it:color){
            diffcol.push_back(it.first);
        }
        if(diffcol.size()==2){
            if(color[diffcol[0]]>1 && color[diffcol[1]]>1){
                possible = false;
            }
        }
        if(possible){
            ans = m;
        }
        else{
                
        }
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