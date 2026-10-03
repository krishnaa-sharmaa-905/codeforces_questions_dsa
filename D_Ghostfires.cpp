#include <bits/stdc++.h>
using namespace std;

bool static comp(pair<int,int> a, pair<int,int> b){
    return a.first>=b.first;
}

void solve() {
    int r,g,b;
    cin>>r>>g>>b;
    vector<pair<int,char>> help;
    help.push_back({r,'R'});
    help.push_back({b,'B'});
    help.push_back({g,'G'});
    string ans = "";
    
    while(true){
        int prev_size = ans.size();
        sort(help.begin(),help.end(),comp);
        for(int i = 0;i<3;i++){
            if(help[i].first>0){
                if(ans.size()>0 && ans[ans.size()-1] == help[i].second){
                    continue;
                }
                if(ans.size()>2 && ans[ans.size()-3] == help[i].second){
                    continue;
                }
                ans += help[i].second;
                help[i].first--;
                break;
            }
        }
        if(ans.size()==prev_size) break;

    }
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