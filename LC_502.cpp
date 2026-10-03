#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;



int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        int ini = w;
        using t = pair<int,int>;
        int ans = 0;
        priority_queue<t, vector<t>, greater<t>> pq1;
        priority_queue<t, vector<t>, greater<t>> pq2;
        for(int i =  0;i<n;i++){
            pq1.push({-1*profits[i], capital[i]});
        }
        while(k && !pq1.empty()){
            // while(!pq1.empty()){
                auto it = pq1.top();
                pq1.pop();
                if( it.second <= w){//change
                    w+= it.first*-1;
                    ans += it.first;
                    k--;
                    while(!pq2.empty()){
                        auto it2 = pq2.top();
                        pq2.pop();
                        pq1.push(it2);
                    }
                }
                else{
                    pq2.push(it);
                }
            // }
    }
    return ans*-1 + ini;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//     3
// 0
// [1,2,3]
// [0,1,2]
cout<<"Hello World"<<endl;
    vector<int> profits = {1,2,3};
    vector<int> capital = {1,1,2};
    int ans = findMaximizedCapital(1,2,profits,capital);
    cout<<ans<<endl;

    return 0;
}