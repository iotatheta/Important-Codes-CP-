// ω(n) (Small Omega)
// omega[n] = number of distinct prime divisors of n
// From the divisors of n just select the prime numbers

// N * (1/2 + 1/3 + 1/5 + 1/7 ... + 1/N) = O(N log log N)
// Sum of reciprocal of primes give TC: O(log log N)

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

vector<ll> omega(N+1) ;

void precompute()
{
    
    for(ll i=2;i<=N;i++)
    {
        if(omega[i] == 0) // Prime Check
        {
            for(ll j=i;j<=N;j+=i)
            {
                omega[j]++ ;
            }
        }
    }
    
}
// TC: O(N log log N)
// SC: O(N)

void solve()
{
    ll n ;
    cin >> n ;
    
    cout << omega[n] << endl ;
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
        solve() ;
    }
}
// TC: O(N log log N + T)
// SC: O(N)
