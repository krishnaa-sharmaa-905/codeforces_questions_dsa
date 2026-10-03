#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#define ll long long
using namespace std;

void solve()
{
    priority_queue<ll, vector<ll>, greater<ll>> minpq;
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        minpq.push(temp);
    }
    ll count = 0;
    ll current = minpq.top();
    count++;
    minpq.pop();
    while(!minpq.empty()){
        ll next = minpq.top();
        minpq.pop();
        if(next==current){
            count++;
            if(count==3){
                count--;
                minpq.push(next+1);
            }
            
        }
        else{
            if(count==1){
                cout<<"No\n";
                return;
            }
            current = next;
            count = 1;
        }
    }
    cout<<"Yes\n";
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