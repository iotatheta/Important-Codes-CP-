/*
A certain number 1≤𝑥≤1e9
 is chosen. You are given two integers 𝑎
 and 𝑏, which are the two largest divisors of the number 𝑥. At the same time, the condition 1≤𝑎<𝑏<𝑥is satisfied.

For the given numbers 𝑎, 𝑏, you need to find the value of 𝑥

Input : 
8
2 3
1 2
3 81
1 5
5 10
4 6
3 9
250000000 500000000

Output:
6
4
243
25
20
12
27
1000000000
*/

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define ll long long
#define endl '\n'

ll gcd(ll a, ll b)
{
    a = llabs(a);
    b = llabs(b);
    
    while(b != 0)
    {
        ll rem = a % b;
        a = b;
        b = rem;
    }
    
    return a;
}

ll lcm(ll a, ll b)
{
    if(a == 0 || b == 0)
        return 0;
        
    ll d = gcd(a, b);
    return llabs((a / d) * b);
}

// Returns n × smallest prime factor
ll func(ll n)
{
    if(n % 2 == 0)
        return n * 2;

    for(ll i = 3; i * i <= n; i += 2)
    {
        if(n % i == 0)
            return n * i;
    }

    return n * n;
}
// TC: O(√n)
// SC: O(1)

void solve()
{
    ll a, b;
    cin >> a >> b;

    if(b % a == 0)
        cout << func(b) << '\n';
    else
        cout << lcm(a, b) << '\n';
}
// TC: O(log(min(a,b)) + √b)
// SC: O(1)

int main()
{
    fastio();
    ll t;
    cin >> t;
    while(t-- > 0)
    {
        solve();
    }
}
