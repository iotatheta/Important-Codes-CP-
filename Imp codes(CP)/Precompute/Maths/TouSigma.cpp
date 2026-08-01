// tau[n]   = number of divisors of n
// sigma[n] = sum of divisors of n
// Starting from i = 2 saves 1e6 operations

// N * (1/2 + 1/3 + 1/4 + ... + 1/N) = O(N log N)

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define ll long long
#define endl '\n'

const ll N = 1e6 ;

vector<ll> tou(N+1,1), sigma(N+1,1) ;

void precompute()
{
    tou[0] = 0, tou[1] = 1 ;
    
    sigma[0] = 0, sigma[1] = 1 ;
    
    for(ll i=2;i<=N;i++)
    {
        for(ll j=i;j<=N;j+=i)
        {
            tou[j]++ ;
            sigma[j] += i ;
        }
    }
    
}
// TC: O(N log N)
// SC: O(N)

void solve()
{
    ll n ;
    cin >> n ;
    
    cout << tou[n] << " " << sigma[n] << endl ;
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
// TC: O(N log N + T)
// SC: O(N)
