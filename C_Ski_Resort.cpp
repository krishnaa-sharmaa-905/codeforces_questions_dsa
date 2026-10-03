#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

long long atmostSubarray(vector<int> &a, int k, int q) {
    int n = a.size();
    int l = 0, r = 0;
    long long ans = 0;
    long long cnt = 0;
    for(int i = 0; i<n; i++){
        if(a[i]<=q){
            cnt++;
        }
        else{
            if(cnt>=k){
                ans += (cnt * (cnt + 1) / 2) - ((k - 1) * cnt - (k - 2) * (k - 1) / 2);
            }
         

            cnt = 0;
        }
    }
    if(cnt>=k){
       ans += (cnt * (cnt + 1) / 2) - ((k - 1) * cnt - (k - 2) * (k - 1) / 2);
    }
    
    return ans;
}

void solve(){
    int n,k,q;
    cin>>n>>k>>q;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    
   
   
    long long ans = atmostSubarray(a,k,q);
   
    cout<<ans<<endl;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}