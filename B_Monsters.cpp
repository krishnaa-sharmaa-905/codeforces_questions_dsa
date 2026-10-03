/*

ATTEMPT 1 


*/





// #include <iostream>
// #include<vector>
// #include<string>
// #include<algorithm>
// #include<cmath>
// #include<queue>
// using namespace std;

// struct Compare {
//     bool operator()(pair<int, int> a, pair<int, int> b) {
//         if (a.first == b.first)
//             return a.second > b.second; // Lower second comes first
//         return a.first < b.first; // Max heap for first
//     }
// };

// void solve(){
//     int n,k;
//     cin>>n>>k;
//     vector<int> a(n);
//     for(int i = 0; i<n; i++){
//         cin>>a[i];
//     }
//     priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
//     for(int i = 0; i<n; i++){
//         pair<int,int> temp;
//         temp ={a[i],i+1};
//         pq.push(temp);
//     }vector<int> ans;
//     while(!pq.empty()){
//         if(pq.top().first<=k){
//             ans.push_back(pq.top().second);
//             pq.pop();
//         }
//         else{//chota hai toh kam karke dubara daaldo
//             pair<int,int> curr = pq.top();
//             pq.pop();
//             curr.first -= k;
//             pq.push(curr);
//         }
//     }
//     for(int i = 0; i<n; i++){
//         cout<<ans[i]<<" ";
//     }
//     cout<<endl;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }

#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> hp(n);
    for(int i = 0; i<n; i++){
        int num;
        cin>>num;
        if(num%k==0){
            hp[i] = {k,-i};
        }
        else{
            hp[i] = {num%k,-i};
        }
    }
    sort(hp.begin(),hp.end());
    
    for(int i = n-1; i>=0; i--){
        cout<<abs(hp[i].second)+1<<" ";
    }
    cout<<endl;
    
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