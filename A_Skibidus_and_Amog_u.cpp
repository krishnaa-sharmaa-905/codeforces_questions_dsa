#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

void solve(){
    string w;
    cin>>w;
    int n = w.size();
    w[n-2] = 'i';
    string ans;
    for(int i = 0; i<n-1; i++){
        ans+=w[i];
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