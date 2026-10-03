#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a;
    vector<int> b;
    for(int i = 0; i<n; i++){
        int num;
        cin>>num;
        a.push_back(num);
    }
    for(int i = 0; i<m; i++){
        int num;
        cin>>num;
        b.push_back(num);
    }
    int curr = b[0];
    vector<int> disorder_positions;
    int o = -1;
    int t = -1;
    
    for(int i = 0; i<n-1; i++){
        if(a[i]>a[i+1]){
            disorder_positions.push_back(i);
        }
    }
    int change = disorder_positions.size();
    // cout<<"change: "<<change<<endl;
    if(change>=2){
        cout<<"NO"<<endl;
        
    }
    
    else if(change==0){
        cout<<"YES"<<endl;
    }
    
    
    
        else if(change == 1) {
            int new_a = curr - a[o];
            if (new_a <= a[o + 1]) {
                
                 cout << "YES" << endl;
                
            }
            else{
                cout<<"NO"<<endl;
            }
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