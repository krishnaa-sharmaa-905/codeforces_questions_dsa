#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_map>
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
    int n;
    cin>>n;
    vector<int> a(n);
    unordered_map<int,int> mpp;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        mpp[a[i]]++;
    }

    vector<int> temp;
    temp = a;
    for(int i = 0; i<n; i++){
        temp[i]=mpp[a[i]];
    }
    int l = 0;
    int r = 0;
    int ansl = -1;
    int ansr = -1;
    int maxi = 0;
    int currl = 0;
    while(r<n){
        if(temp[r]==1){
            currl++;

            if(currl>maxi){
                maxi = currl;
                ansl = l;
                ansr = r;
            }
        }
        else{
            currl = 0;
            l=r+1;
        }
        r++;
        
    }
    if(ansl<0 && ansr<0){
        cout<<0<<endl;
    }
    else{
        cout<<ansl+1<<" "<<ansr+1<<endl;
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