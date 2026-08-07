// Bezout't identity for 3 numbers (similiar method  is applicable for n numbers)

// First find extended_gcd for 2 numbers and then use it for third number
/*
Mathematical Verification:
    
Step 1:
    Extended Euclidean Algorithm gives
    
         a*u + b*v = gcd(a, b) = d
    
Step 2:
    Apply Extended Euclid again on d and c
    
         d*X + c*Z = gcd(d, c) = gcd(a, b, c) = g
    
Step 3:
    Substitute d = a*u + b*v into the second equation
    
         (a*u + b*v) * X + c*Z = g
    
    Expanding,
    
         a*(u*X) + b*(v*X) + c*Z = g
    
    Therefore,
    
         x = u * X
         y = v * X
         z = Z
    
    satisfy
    
         a*x + b*y + c*z = gcd(a, b, c)
    
The same idea generalizes naturally to n numbers by repeatedly applying Extended Euclid on the current gcd and the next number.
*/

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
// SC: O(log(min(a, b)))   // Recursive call stack

void solve()
{
    ll a, b, c, x, y, z;
    cin >> a >> b >> c;
    
    ll u, v;
    ll d = extended_gcd(a, b, u, v);
    
    ll X, Z;
    ll g = extended_gcd(d, c, X, Z);
    
    x = u * X;
    y = v * X;
    z = Z;
    
    cout << a << "x + " << b << "y + " << c << "z = " << g << endl << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z;
}
// Two calls to Extended Euclid
// TC: O(log(min(a, b)) + log(min(gcd(a, b), c)))
// SC: O(log(max(a, b, c)))   // Maximum recursion depth of either call

int main()
{
    fastio();
    solve();
}
// TC: O(log(min(a, b)) + log(min(gcd(a, b), c)))
// SC: O(log(max(a, b, c)))   // Recursive stack
