// Iterative GCD
// Recursive GCD
// LCM

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define endl '\n'

// Euclidean Algorithm (Iterative)
ll iterativeGCD(ll a, ll b)
{
    a = llabs(a);
    b = llabs(b);

    while (b != 0)
    {
        ll r = a % b;
        a = b;
        b = r;
    }

    return a;
}
// TC: O(log(min(a, b)))
// SC: O(1)

// Euclidean Algorithm (Recursive)
ll recursiveGCD(ll a, ll b)
{
    a = llabs(a);
    b = llabs(b);

    if (b == 0)
        return a;

    return recursiveGCD(b, a % b);
}
// TC: O(log(min(a, b)))
// SC: O(log(min(a, b)))   // Recursive call stack

// Least Common Multiple
ll lcm(ll a, ll b)
{
    if (a == 0 || b == 0)
        return 0;

    ll d = iterativeGCD(a, b);
    return llabs((a / d) * b);
}
// TC: O(log(min(a, b)))
// SC: O(1)

void solve()
{
    ll a, b;
    cin >> a >> b;

    cout << iterativeGCD(a, b) << endl;
    cout << recursiveGCD(a, b) << endl;
    cout << lcm(a, b) << endl;
}
// TC: O(log(min(a, b)))
// SC: O(1)

int main()
{
    fastio();
    solve();
}
// TC: O(log(min(a, b)))
// SC: O(log(min(a, b)))   // Due to recursiveGCD()