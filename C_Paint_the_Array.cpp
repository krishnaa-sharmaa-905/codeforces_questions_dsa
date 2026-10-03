#include <iostream>
#include <vector>
#include <numeric>
#define ll long long
#define vll vector<long long>
using namespace std;
 
void solve()
{
    ll n;
    cin >> n;
    vll a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
 
    ll gcdo = a[0], gcde = a[1];
 
    for (ll i = 0; i < n; i += 2)
        gcdo = gcd(gcdo, a[i]);
    for (ll i = 1; i < n; i += 2)
        gcde = gcd(gcde, a[i]);
 
    bool valido = true, valide = true;
 
    for (ll i = 1; i < n; i += 2)
    {
        if (a[i] % gcdo == 0)
            valido = false;
    }
 
    for (ll i = 0; i < n; i += 2)
    {
        if (a[i] % gcde == 0)
            valide = false;
    }
 
    if (valido)
    {
        cout << gcdo << endl;
        return;
    }
    if (valide)
    {
        cout << gcde << endl;
        return;
    }
 
    cout << 0 << endl;
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