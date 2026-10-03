#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;

unordered_map<ll, ll> maxlen(vector<ll>& nums) {
    int n = nums.size();
    unordered_map<ll, ll> mpp;
    // ll r-l+1 = 0;
    ll l = 0;
    ll r = 0;
    while (r < n) {
        if (nums[l] != nums[r]) {
            mpp[nums[l]] = max(mpp[nums[l]], r - l);
            // r-l+1++;
            l = r;
        }
        r++;
    }
    mpp[nums[l]] = max(mpp[nums[l]], n - l);
    return mpp;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    unordered_map<ll, ll> numa = maxlen(a);
    unordered_map<ll, ll> numb = maxlen(b);
    //     cout<<"test"<<endl;
    // //test
    //     for (const auto& pair : numa) {
    //         cout << "Key: " << pair.first << ", Value: " << pair.second << "
    //         -> ";
    //     }
    //     cout<<endl;

    //     for (const auto& pair : numb) {
    //         cout << "Key: " << pair.first << ", Value: " << pair.second << "
    //         -> ";
    //     }
    //     cout<<endl;

    //     //test
    for (auto num : numa) {
        if (numb.find(num.first) != numb.end()) {
            numb[num.first] = num.second + numb[num.first];
        } else {
            numb[num.first] = num.second;
        }
    }
    ll ans = 0;

    for (auto num : numb) {
        ans = max(ans, num.second);
    }
    cout << ans << endl;
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