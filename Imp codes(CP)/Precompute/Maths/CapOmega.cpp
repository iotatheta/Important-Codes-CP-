// Ω(n) (Capital Omega)
// Ω(n) = total number of prime factors counting multiplicity.
/*
 e.g : 72 = 2³ × 3²
    ω(72) = 2
    Ω(72) = 5
*/

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define endl '\n'

const ll N = 1e6 ;

vector<ll> spf(N+1), capOmega(N+1) ;

void precomputeSPF()
{
    for(ll i=2;i<=N;i++)
    {
        if(spf[i] == 0) // Prime check
        {
            for(ll j=i;j<=N;j+=i)
            {
                if(spf[j] == 0)
                {
                    spf[j] = i ;
                }
            }
        }
    }
    
}
// TC: O(N log log N)
// SC: O(N)

void precomputeCapOmega()
{
    ll cnt = 0, temp ;
    
    for(ll i=2;i<=N;i++)
    {
        cnt = 0 ;
        temp = i ;
        
        while(temp != 1)
        {
            cnt++;
            temp /= spf[temp];
        }
        
        capOmega[i] = cnt ;
    }
} 
// This is for reference only (no use)
// TC: O(N log log N) [worst O(N log N) but very rare]
// SC: O(N) 

void precomputeCapOmegaOmptimised()
{
    capOmega[1] = 0;

    for(ll i=2;i<=N;i++)
    {
        capOmega[i] = capOmega[i / spf[i]] + 1;
    }
    
} 
// Always use this
// TC: O(N)
// SC: O(N)

void solve()
{
    ll n ;
    cin >> n ;
    
    cout << capOmega[n] << endl ;
}
// TC: O(1)
// SC: O(1)

int main()
{
    fastio();
    precomputeSPF();
    precomputeCapOmegaOmptimised();
    
    ll t ;
    cin >> t ;
    
    while(t-- > 0)
    {
        solve() ;
    }
}
// TC: O(N log log N + T)
// SC: O(N)

/*
Recurrence:

Divide the number by its smallest prime factor.
This removes exactly ONE prime factor.

Therefore,

    Ω(n) = Ω(n / spf[n]) + 1

Example:

    72 = 2 × 2 × 2 × 3 × 3
    
Now, 72 / spf[72]
    = 72 / 2
    = 36
    
And, 36 = 2 × 2 × 3 × 3
    
    Ω(36) = 4
    
So,
    Ω(72) = Ω(36) + 1
           = 4 + 1
           = 5

Since (n / spf[n]) < n, we compute Ω[] in increasing order (DP).
*/