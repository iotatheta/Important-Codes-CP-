// Euler Totient Function (Phi Function)
// φ(n) = Number of integers from 1 to n that are coprime with n i.e (i,n) = 1
// res -= res/i to handle overflow
// Or simply use res = (res / i) * (i - 1) to handle overflow

// Use Odd Optimisation i.e treat even and odd seperately

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define endl '\n'

const ll N = 1e6 ;

vector<ll> phi(N+1) ;

void precomputePhi()
{
    for(ll i=0;i<=N;i++)
    {
        phi[i] = i ;
    }
    
    for(ll i=2;i<=N;i+=2)
    {
        phi[i] = phi[i] / 2 ;
    }
    // Treat even
    
    for(ll i=3;i<=N;i+=2)
    {
        if(phi[i] == i) // Prime Check
        {
            for(ll j=i;j<=N;j+=i)
            {
                phi[j] = (phi[j] / i) * (i - 1) ;
            }
        }
    }
    // Treat odd
}
// TC: O(N log log N)
// SC: O(N)

void solve()
{
    ll n ; 
    cin >> n ;
    
    for(ll i=0;i<=n;i++)
    {
        cout << i << " : " << phi[i] << endl ;
    }
}
// TC: O(n)
// SC: O(1)

int main()
{
    fastio();
    precomputePhi();
    
    solve();
}
// TC: O(N log log N + n)
// SC: O(N)
