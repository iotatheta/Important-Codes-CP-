// Euler Totient Function (Phi Function)
// φ(n) = Number of integers from 1 to n that are coprime with n i.e (i,n) = 1
// res -= res/i to handle overflow

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
                phi[j] -= phi[j] / i;
            }
        }
    }
} // TC : O(N log log N) , SC : O(N)

ll phiFunc(ll n)
{
    ll res = n;
    for(ll i=2;i*i<=n;i++)
    {
        if(n % i == 0)
        { 
            // to handle overflow
            res = (res / i) * (i - 1);
            while(n % i == 0)
            {
                n /= i;
            }
        }
    }
    if(n > 1)
        res = (res / n) * (n - 1);
        
    return res;
} // TC : O(√n) , SC : O(1)

ll optimisedPhi(ll n)
{
    ll res = n;
    if(n % 2 == 0)
    {
        res -= res / 2;
        while(n % 2 == 0)
        {
            n /= 2;
        }
    }
    for(ll i=3;i*i<=n;i+=2)
    {
        if(n % i == 0)
        {
            res -= res / i;
            while(n % i == 0)
            {
                n /= i;
            }
        }
    }
    if(n > 1)
        res -= res / n;
        
    return res;
} // TC : O(√n) , SC : O(1)

void solve()
{
    ll n;
    cin>>n;
    if(n <= 1e6)
        cout<<phi[n];
    else
        cout<<optimisedPhi(n);
} // TC : O(1) (precomputed) or O(√n) , SC : O(1)

int main()
{
    fastio();
    precompute();
    solve();
} // TC : O(N log log N + Query) , SC : O(N)
