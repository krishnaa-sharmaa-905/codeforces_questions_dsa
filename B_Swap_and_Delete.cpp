#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

int check(string &s,int no1, int no0){
    int ans = 0;
    int i;
    for(i = 0;i<s.size();i++){
        if(s[i]=='1' ){
            if(no0>0){
                no0--;
            }
            else break;
            
        }
        else if(s[i]=='0' ){
            if(no1>0){
                no1--;
            }
            else break;
        }

        

    }
    return s.size()-i;
}

void solve(){

    string s = "";
    cin>>s;
    string t="";
    int n = s.size();
    int no0 = 0;
    int no1 = 0;
    for(char ch:s){
        if(ch=='1') no1++;
        else no0++;
    }
    if(no0==no1 ) {
        cout<<0<<endl;
        return;
        }
    else if(no1==0 || no0==0){
         cout<<n<<endl;
         return;
    }
    
    int ans = check(s,no1,no0);
    cout<<ans<<endl;
    return;
    

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