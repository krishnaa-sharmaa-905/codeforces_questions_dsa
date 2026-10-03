#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include <unordered_map>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    unordered_map<char,int> mppl;
    unordered_map<char,int> mppr;
    for(char c:s){
        mppr[c]++;
    }
    
    int ans = 0;
    for(int i = 0; i<n; i++){
        mppl[s[i]]++;
        mppr[s[i]]--;
        if(mppr[s[i]]==0){
            mppr.erase(s[i]);
        }        
        int curr= mppl.size()+mppr.size();
        ans= max(ans,curr);
    }
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