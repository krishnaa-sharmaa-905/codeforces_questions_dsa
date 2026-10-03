#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n,q;
    cin>>n>>q;
    vector<vector<int>> io(q,vector<int>(2,0));

    for(int i = 0 ;i<q;i++){
        cin>>io[i][0]>>io[i][1];
    }
    vector<int> a(n,0);
    vector<int> b(n,0);
    for(int i =  0; i<q;i++){
        int ind = io[i][0];
        int x = io[i][1];
        int r = min(n-1,ind + x - 1);

        a[ind] += -1;
        a[r+1] += +1;
        b[ind] += (x+ind);
        b[r+1] -= (x+ind);

        int l = max(0,ind-x+1);

        a[l] +=1;
        a[ind] -= 1;
        b[l] += (x-ind);
        b[ind] -= (x-ind);

    }
    vector<int> ans(n,0);
    int A = 0;
    int B = 0;
    for(int i = 0;i<n;i++){
        A += a[i];
        B += b[i];
        ans[i] = A*i + B;
    }
    for(int i = 0; i<n; i++) cout<<ans[i]<<" ";
}

int main(){
    solve();
    return 0;
}



// #include <bits/stdc++.h>
// using namespace std;

// string s;
// int dp[505][505];

// int solve(int l, int r){
//     if(l > r) return 0;
//     if(l == r) return 1;

//     if(dp[l][r] != -1) return dp[l][r];

//     // Case 1: remove s[l] alone
//     int ans = 1 + solve(l+1, r);

//     // Case 2: try merging
//     for(int k = l+1; k <= r; k++){
//         if(s[l] == s[k]){
//             ans = min(ans,
//                 solve(l+1, k-1) + solve(k, r));
//         }
//     }

//     return dp[l][r] = ans;
// }

// int getMinArchiveOperations(string str){
//     s = str;
//     int n = s.size();

//     memset(dp, -1, sizeof(dp));

//     return solve(0, n-1);
// }

// int main(){
//     string s;
//     cin >> s;
//     cout << getMinArchiveOperations(s);
// }





bool solve(int k, int diff, vector<int> &a){
    int n = a.size();
    int cnt = 0;
    int last = a[0];
    for(int i=1;i<n;i++){
        if(a[i]-last >= diff){
            cnt++;
            last = a[i];
        }
        if(cnt >= k) return true;
    }
    return false;
}