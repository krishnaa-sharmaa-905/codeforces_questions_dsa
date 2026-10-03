#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

void solve(){
    int x,y;
    cin>>x>>y;
    string s1 = "";
    string s2 = "";
    int halfx = x/2;
    int halfy = y/2;
    for(int i = 0; i<halfx; i++){
        s1 += '1';
    }
    for(int i = 0; i<halfy; i++){
        s1 += '2';
    }
    for(int i = 0; i<halfy; i++){
        s1 += '2';
    }
    for(int i = 0; i<halfx; i++){
        s1 += '1';
    }
    cout<<s1<<endl;


    
    
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