// Bezout's Identity
// Extended Euclidean Algorithm

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define endl '\n'

ll extended_gcd(ll a, ll b, ll &x, ll &y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    
    ll x1, y1;
 
    ll gcd = extended_gcd(b, a % b, x1, y1);
    
    x = y1;
    y = x1 - (a / b) * y1;
    
    return gcd;
}
// TC: O(log(min(a, b)))
// SC: O(log(min(a, b)))   // Recursive stack

void solve()
{
    ll a, b, x, y;
    cin >> a >> b;
    
    ll gcd = extended_gcd(a, b, x, y);
    
    cout << a << "x + " << b << "y = " << gcd << endl << endl;
    cout << "x = " << x << endl << "y = " << y;
}
// TC: O(log(min(a, b)))
// SC: O(log(min(a, b)))

int main()
{
    fastio();
    solve();
}
// TC: O(log(min(a, b)))
// SC: O(log(min(a, b)))
