// Precompute Factorial and Inverse Factorial
// Use it for modulo nCr and nPr
// By Fermat's Little Theorem
// If p is prime and (a, p) = 1
// a^(p-2) = a^-1 (mod p)

// Avoid default modulus parameters in fixed-mod precomputation libraries.
// All functions use the same global MOD.

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define endl '\n'

#define i128 __int128

const ll N = 1e6 ;
const ll MOD = 1e9 + 7 ;

vector<ll> fact(N+1), invfact(N+1) ;

// No modulus parameter is needed because the entire library uses the same MOD.

ll power(ll a, ll b) 
{
    if(b == 0)
        return 1 ;
    
    a = ( a % MOD + MOD ) % MOD ;
    ll res = 1 ;
    
    while(b > 0)
    {
        if(b & 1)
            res = (i128) res * a % MOD ;
        a = (i128) a * a % MOD ;
        b = b >> 1 ;
    }
    
    return res ;
}
// TC: O(log MOD)
// SC: O(1)

ll inverse(ll a)
{
    return power(a, MOD - 2);
}
// TC: O(log MOD)
// SC: O(1)

void precompute()
{
    fact[0] = 1 ;
    
    for(ll i=1;i<=N;i++)
    {
        fact[i] = (i128) fact[i-1] * i % MOD ;
    }
    // TC: O(N)
    
    invfact[N] = inverse(fact[N]) ; // TC: O(log MOD)
    
    for(ll i=N;i>=1;i--)
    {
        invfact[i-1] = (i128) invfact[i] * i % MOD ;
    }
    // TC: O(N)
}
// TC: O(N + log MOD)
// SC: O(N)

ll C(ll n, ll r)
{
    if(r < 0 || r > n)
        return 0 ;
        
    return (i128) ((i128) fact[n] * invfact[r] % MOD ) * invfact[n-r] % MOD ;
}
// TC: O(1)
// SC: O(1)

ll P(ll n, ll r)
{
    if(r < 0 || r > n)
        return 0 ;
        
    return (i128) fact[n] * invfact[n-r] % MOD ;
}
// TC: O(1)
// SC: O(1)

void solve()
{
    ll n, r ;
    cin >> n >> r ;
    
    cout << C(n, r) << " " << P(n, r) << endl ;
}
// TC: O(1)
// SC: O(1)

int main()
{
    fastio();
    precompute();
    
    ll t ; 
    cin >> t ;
    
    while(t-- > 0)
    {
        solve();
    }
}
// TC: O(N + log MOD + T)
// SC: O(N)
