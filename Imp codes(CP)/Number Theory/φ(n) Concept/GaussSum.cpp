// Gauss Divisor Sum Property
// ∑ϕ(d) = n , where d are the divisors of n
	
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
    } // O(N) 
    
    for(ll i=2;i<=N;i++)
    {
        if(phi[i] == i)
        {
            for(ll j=i;j<=N;j+=i)
            {
                phi[j] = (phi[j] / i) * (i - 1);
            }
        }
    }
} // Time: O(N log log N) , Space: O(N)

ll phiFunc(ll n)
{
    ll res = n;
    if(n % 2 == 0)
    {
        res = res / 2;
        while(n % 2 == 0)
        {
            n /= 2;
        }
    }
    for(ll i=3;i*i<=n;i+=2)
    {
        if(n % i == 0)
        {
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
} // Time: O(√n) , Space: O(1)

// sum of ϕ of proper divisors
void solve()
{
    ll n;
    cin>>n;
    if(n <= 1e6)
        cout<< n - phi[n] << endl;
    else
        cout<< n - phiFunc(n) <<endl;
}

int main()
{
    fastio();
    precompute();
    ll t;
    cin>>t;
    while(t-- > 0)
    {
        solve();
    }
}