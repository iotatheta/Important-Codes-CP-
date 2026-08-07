// CRT ( Chinese Remainder Theorem )
// Works only when all moduli are pairwise coprime
// Assumes product of all moduli fits in long long

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define endl '\n'

#define i128 __int128

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

ll inverse(ll a, ll mod)
{
    ll x, y;
    
    ll g = extended_gcd(a, mod, x, y);
    
    if(g != 1)
        return -1; // inverse doesn't exist
        
    return (x % mod + mod) % mod;
}
// TC: O(log(mod))
// SC: O(log(mod)))

ll chinese_remainder(const vector<ll> &a, const vector<ll> &m, ll M)
{
    ll Mi, n = a.size(), x = 0, inv;
    
    for(ll i=0;i<n;i++)
    {
        Mi = M / m[i];
        inv = inverse(Mi, m[i]);
        
        if(inv == -1)
            return -1;
        
        x = (x + (i128) a[i] * Mi % M * inv % M) % M;
    }
    
    return (x + M) % M;
}
// TC: O(n log(max(m[i])))
// SC: O(1)

void solve()
{
    ll n, M = 1;
    cin >> n;
    
    vector<ll> a(n), m(n);
    
    for(ll i=0;i<n;i++)
    {
        cin >> a[i];
    }
    
    for(ll i=0;i<n;i++)
    {
        cin >> m[i];
        M *= m[i];
    }
    
    cout << "x = " << chinese_remainder(a, m, M) << " (mod " << M << ")";
}
// TC: O(n log(max(m[i])))
// SC: O(n)

int main()
{
    fastio();
    solve();
}
// TC: O(n log(max(m[i])))
// SC: O(n)


// ======= Chinese Remainder Theorem (CRT) =========//

// We are given:
//
//     x ≡ a1 (mod m1)
//     x ≡ a2 (mod m2)
//     ...
//     x ≡ an (mod mn)
//
// Assumption:
//     All moduli m1, m2, ..., mn are pairwise coprime.
//
// Let:
//
//     M = m1 × m2 × ... × mn
//     Mi = M / mi
//
// Since Mi contains every modulus except mi:
//
//     Mi ≡ 0 (mod mj)   for all j ≠ i
//
// Thus, Mi automatically makes the i-th term vanish modulo every other modulus.
//
// We now need Mi to become 1 modulo mi:
//
//     Mi × inv(Mi) ≡ 1 (mod mi)
//
// Why Extended Euclidean Algorithm?
//
//     We need:
//
//         Mi × inv(Mi) ≡ 1 (mod mi)
//
//     By the definition of congruence:
//
//         Mi × inv(Mi) + mi × y = 1
//
//     This is exactly Bézout's Identity, which is solved by the
//     Extended Euclidean Algorithm.
//
//     Since gcd(Mi, mi) = 1 (pairwise coprime moduli),
//     the inverse always exists.
//
// Therefore,
//
//     ai × Mi × inv(Mi)
//
// satisfies:
//
//     ≡ ai (mod mi)
//     ≡ 0  (mod mj),  j ≠ i
//
// Hence, each term contributes only to its own congruence.
//
// Adding all such terms gives:
//
//     x = Σ (ai × Mi × inv(Mi)) (mod M)
//
// because modulo mi:
//
//     x ≡ ai + 0 + 0 + ... + 0
//       ≡ ai (mod mi)
//
// Therefore, x simultaneously satisfies every congruence.
//
// Formula:
//
//     x = Σ (ai × Mi × inv(Mi)) (mod M)
//
//====================================================== //