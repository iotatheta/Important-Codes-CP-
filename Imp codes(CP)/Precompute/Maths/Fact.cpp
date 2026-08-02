// Precompute Factorial
// Use the precomputed factorial to compute the factorial function

// Without implementing from scratch try to reuse precomputed value

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define endl '\n'

#define i128 __int128

const ll N = 1e6 ;
const ll MOD = 1e9 + 7 ;

vector<ll> fact(N+1) ;

void precomputeFact()
{
    fact[0] = 1 ;
    
    for(ll i=1;i<=N;i++)
    {
        fact[i] = (i128) fact[i-1] * i % MOD ;
    }
}
// O(N)
// O(N)

ll factorial(ll n)
{
    // If n >= MOD then n! will contain MOD 
    if(n >= MOD)
        return 0 ;
        
    ll res = fact[N] ;
    
    // starting from i = N+1 will save 1e6 operations
    
    for(ll i=N+1;i<=n;i++)
    {
        res = (i128) res * i % MOD ;
    }
    
    return res ;
}
// TC: O(1) if n ≤ N or n ≥ MOD, otherwise O(n−N)
// TC: O(1)

void solve()
{
    ll n ;
    cin >> n ;
    
    if(n <= N)
        cout << fact[n] << endl ;
    else
        cout << factorial(n) << endl ;
}
// TC: O(1) or O(n−N)
// TC: O(1)

int main()
{
    fastio();
    precomputeFact();
    
    ll t ;
    cin >> t ;
    
    while(t-- > 0)
    {
        solve() ;
    }
}
// TC: O(N + Σ max(1, nᵢ−N))
// SC: O(N)
