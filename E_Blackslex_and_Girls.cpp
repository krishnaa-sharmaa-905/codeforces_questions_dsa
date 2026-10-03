#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;



void solve() {
    int n,x,y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    vector<int> p(n);
    for(int i = 0; i<n; i++){
        cin>>p[i];
        // cout<<p[i]<<" ";
    }
    // cout<<endl;
    int cnt0 = 0;
    for(int i = 0; i<n; i++){
        if(s[i]=='0'){
            cnt0++;
        }
    }
    int cnt1 = n - cnt0;
//base condition
    if(cnt0==n && y>=x){
        cout<<"NO" <<endl;
        return;
    }
    if(cnt1==n && x>=y){
        cout<<"NO" <<endl;
        return;
    }

    vector<int> a(n,0);
    vector<int> b(n,0);
    for(int i = 0; i<n; i++){
        int num1 = 0;
        int num2 = 0;
        
        if(p[i]%2==0){
            num1 = (p[i]/2) + 1;
            num2 = (p[i]/2) - 1;
        }
        else{
            num1 = (p[i]/2) +1;
            num2 =  p[i]/2;
        }

        if(s[i]=='0'){
            a[i]=max(num1,num2);
            b[i] = min(num1,num2);
        }
        else{
            b[i]=max(num1,num2);
            a[i] = min(num1,num2);
        }

    }
    // cout<<"test -> "<<endl;
    // for(int i = 0; i<n; i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    // for(int i = 0; i<n; i++){
    //     cout<<b[i]<<" ";
    // }
    // cout<<endl;

    ll sumA = 0;
    ll sumB = 0;

    for(int i = 0; i<n; i++){
        sumA += a[i];
        sumB += b[i];
    }

    //if both need to be increaed/decreased answer is no
    if(sumA<=x && sumB<=y){
        cout<<"YES"<<endl;
        return;
    }
    if(sumA>x && sumB>y){
        cout<<"NO"<<endl;
        return;
    }

    if(sumA>x){
        for(int i = 0;i<n;i++){
            if(s[i]=='1'){
                ll reduce = 1LL*min(sumA - x, (ll)a[i]);
                sumA -= reduce;
                a[i] -= reduce;
                b[i] += reduce;
                sumB += reduce;
                if(sumA<=x && sumB<=y){
                    cout<<"YES"<<endl;
                    return;
                }

            }
        }
    }
    else{
        for(int i = 0;i<n;i++){
            if(s[i]=='0'){
                ll reduce = 1LL*min(sumB - y, (ll)b[i]);
                sumB -= reduce;
                b[i] -= reduce;
                a[i] += reduce;
                sumA += reduce;
                if(sumA<=x && sumB<=y){
                    cout<<"YES"<<endl;
                    return;
                }

            }
        }
    }

    cout<<"NO"<<endl;


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