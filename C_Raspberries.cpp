#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    //case1 jab ek element ho ya 4 ke case 2 *2 wale ho
    int ans = k-1;
    int even =0;
    for(int i = 0; i<n; i++){
        if(a[i]%2==0){
            even++;
        }
        if(a[i]%k==0){
            ans=0;
        }
        else{
            ans = min(ans,k-a[i]%k);
            
        }
    }
    if(k==4){
        
        if(even==1){
            ans = min(ans,1);
        }
        else if(even>=2){
            ans =0;
        }
        else{
            ans = min(2,ans);
        }
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