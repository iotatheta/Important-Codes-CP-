// Lucas Theorem
// Chinese Remainder Theorem (CRT)
// Fermat's Little Theorem (FLT)
// a^(p-2) ≡ a^(-1) (mod p)

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define endl '\n'

#define i128 __int128

ll power(ll a, ll b, ll p)
{
    if(b == 0)
        return 1;
        
    a = (a % p + p) % p;
    ll res = 1;
    
    while(b > 0)
    {
        if(b & 1)
            res = (i128) res * a % p;
        a = (i128) a * a % p;
        b = b >> 1;
    }
    
    return res;
}
// TC: O(log b)
// SC: O(1)

// ---- nCr mod p [for small p] ----

ll nCr(ll n, ll r, ll p)
{
    if(r < 0 || r > n)
        return 0;
        
    r = min(r, n - r);
    
    ll num = 1;
    ll deno = 1;
    
    for(ll i=1;i<=r;i++)
    {
        num = (i128) num * (n - i + 1) % p;
        deno = (i128) deno * i % p;
    }
    
    ll res = (i128) num * power(deno, p - 2, p) % p;
    // Using FLT
    
    return res;
}
// TC: O(min(r,n-r)+log p)
// SC: O(1)

// ---------- Lucas Theorem ---------

ll lucas_nCr(ll n, ll r, ll p)
{
    if(r < 0 || r > n)  
        return 0;
        
    if(r == 0)
        return 1;
    
    ll ni = n % p;
    ll ri = r % p;
    
    return (i128) lucas_nCr(n / p, r / p, p) * nCr(ni, ri, p) % p;
    
}
// TC: O((min(ri, ni-ri) + log p) · logₚ(n))
// SC: O(logₚ(n))

// --- Extended GCD to find Modular Inverse ---

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
// TC: O(log(min(a,b)))
// SC: O(log(min(a,b)))

ll inverse(ll a, ll p)
{
    ll xi, yi;
    
    ll g = extended_gcd(a, p, xi, yi);
    
    if(g != 1)  
        return -1; // Do not exist
        
    xi = xi % p;
    
    if(xi < 0)
        xi += p;
        
    return xi;
}
// TC: O(log p)
// SC: O(log p)

// ---- Combine using CRT ----- 

ll chinese_remainder(const vector<ll>& a, const vector<ll>& m, ll M)
{
    ll n = a.size(), x = 0, Mi, invi;
    
    for(ll i=0;i<n;i++)
    {
        Mi = M / m[i];
        invi = inverse(Mi, m[i]);
        
        x = (x + (i128) a[i] * Mi % M * invi % M) % M;
    }
    
    if(x < 0)
        x += M;
        
    return x;
}
// TC: O(k log(max(mi)))
// SC: O(1)

void solve()
{
    ll N, R, M;
    cin >> N >> R >> M;
    
    if(R < 0 || R > N)
    {
        cout << 0 << endl;
        return;
    }
    
    vector<ll> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    
    // Factorise M into small primes
    vector<ll> a, m;
    
    for(auto p : primes)
    {
        if(M % p == 0)
            m.push_back(p);
    }
    
    // Compute nCr mod each prime (Lucus Theorem)
    for(auto mi : m)
    {
        a.push_back( lucas_nCr(N, R, mi) );
    }
    
    // Combine all using CRT
    cout << chinese_remainder(a, m, M) << endl;
}
// TC: O(k · pmax · logₚₘₐₓ(N))
// SC: O(k + logₚₘₐₓ(N))

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
// TC: O(t · k · pmax · logₚₘₐₓ(N))
// SC: O(k + logₚₘₐₓ(N))
