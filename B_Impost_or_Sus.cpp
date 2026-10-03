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

vector<int> continuous(string &r){
    int n = r.size();
    int i = 0;
    vector<int> ans;
    for(int i =  0;i<n;i++){
        int cnt = 1;
        while(r[i]=='u' && r[i+1]=='u' && i<n-1){
            i++;
            cnt++;
        }
        if(cnt>1){
            ans.push_back(cnt);
        }
    }
    return ans;
}

void solve() {
    string r;
    cin>>r;
    int n = r.size();
    int ucnt = 0;
    int scnt = 0;
    int ans = 0;
    if(r[0]=='u'){
        ans++;
        r[0] = 's';
    }
    if(r[n-1]=='u'){
        ans++;
        r[n-1] = 's';
    }

    for(int i = 0;i<n;i++){
        
        if(r[i]=='s') scnt++;
        else ucnt++;
    }
    vector<int> temp = continuous(r);
    // cout<<"test "<<n<<" "<<endl;
    for(auto it:temp){
        // cout<<it<<" ";
        ans += it/2;
        ucnt -= it/2;
        scnt += it/2;
    }
    if(n%2==0 && ucnt>((n-2)/2)){
        ans += ucnt - ((n-2)/2);
    }
    if(n%2==1 && ucnt> ((n-1)/2)){
        ans += ucnt - ((n-1)/2);
    }
    cout<<ans<<endl;

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