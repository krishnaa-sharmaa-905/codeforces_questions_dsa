#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

bool isPalindrome(string s){
    int n = s.size();
    int i =  0;
    int j = n-1;
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(isPalindrome(s)) {
        cout<<"0"<<endl;
        return;
    }
    set<char> st;
    for(auto it:s){
        st.insert(it);
    }
    int ans = n+1;
    for(auto it:st){
        int i = 0;
        int j = n-1;
        int temp = 0;
        while(i<j){
            if(s[i]==s[j]){
                j--;
                i++;
            }
            else if(s[i] == it){
                i++;
                temp++;
            }
            else if(s[j] == it){
                j--;
                temp++;
            }
            else{
                temp = n+1;
                break;
            }
        }
        ans = min(ans,temp);
    }
    if(ans==n+1) ans=-1;
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}