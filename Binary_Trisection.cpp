#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

bool canBeDivisibleBy3(int ones, int zeros) {
    
    return (ones % 3 == 0);
}

void solve(){
    int n ,q;
    cin>>n>>q;
    string s;
    cin>>s;
    int ones = 0;
    int zeros =0;

    while(q--){
        int l , r;
        cin>>l>>r;
        string curr = "";
        for(int i = l; i<=r; i++){
           curr +=  s[i-1];
        }
        for (char c : curr) {
            if (c == '1') ones++;
            else zeros++;
        }

        if (canBeDivisibleBy3(ones, zeros)) 
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;



    }
    
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