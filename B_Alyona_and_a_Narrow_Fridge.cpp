#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,h;
    cin>>n>>h;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    int s = 0;
    int e = n-1;
    int ans= 0;
    while(s<=e){
        int mid = s + (e-s)/2;
        vector<int> temp(mid+1);
        for(int i  =0;i<=mid;i++){
            temp[i] = a[i];
        }
        sort(temp.begin(),temp.end());

        int req = 0;
        for(int i = mid;i>=0;i = i-2){
            req += temp[i];
            if(req>h) break;
        }
        if(req>h){
            e = mid-1;
        }
        else{
            ans = mid;
            s = mid+1;
        }
    }
    cout<<ans+1<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}