// Modular Exponentiation Simplification
// Euler's Theorem:
// If gcd(a, m) = 1,
// then a^n ≡ a^(n mod φ(m)) (mod m).

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define endl '\n'

const ll N = 1e6;

vector<ll> phi(N+1);
void precompute()
{
    for(ll i=0;i<=N;i++)
    {
        phi[i] = i;
    }
    for(ll i=2;i<=N;i++)
    {
        if(phi[i] == i)
        {
            for(ll j=i;j<=N;j+=i)
            {
                phi[j] = (phi[j] / i) * (i - 1);
                // to avoid overflow
            }
        }
    }
} // TC: O(N log log N) , SC: O(N)

ll phiFunc(ll n)
{
    ll res = n;
    if(!(n & 1))
    {
        res = res / 2;
        while(!(n & 1))
        {
            n /= 2;
        }
    }
    for(ll i=3;i*i<=n;i+=2)
    {
        if(n % i == 0)
        {
            res = (res / i) * (i - 1);
            // to avoid overflow
            while(n % i == 0)
            {
                n /= i;
            }
        }
    }
    if(n > 1)
        res = (res / n) * (n - 1);
        
    return res;
} // TC: O(√m) , SC: O(1)

ll power(ll a,ll b,ll mod = 1e9+7)
{
    if(b == 0)
        return 1;
        
    a = a % mod; // to avoid overflow
    ll res = 1;
    while(b > 0)
    {
        if(b & 1)
            res = (res * a ) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res % mod;
} //TC: O(log n) , SC: O(1)

void solve()
{
    ll a,n,m;
    cin>>a>>n>>m;
    if(m <= 1e6)
        cout<< power(a,n % phi[m],m);
    else
        cout<< power(a,n % phiFunc(m),m);
}

int main()
{
    fastio();
    precompute();
    solve();
}
