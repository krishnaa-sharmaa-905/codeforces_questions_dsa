#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

void solve(){
    string s;
    cin>>s;
    
    int n = s.size();
    
        bool get = false;
        for(int i = 0; i<n; i++){
            if(s[i]==s[i+1]){
                get = true;
                break;
            }
        }
        if(get==true) cout<<1<<endl;

        else{
            cout<<n<<endl;
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