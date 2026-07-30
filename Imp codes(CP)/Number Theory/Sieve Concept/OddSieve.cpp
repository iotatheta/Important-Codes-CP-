// Odd Sieve Optimization
// Sieve of Eratosthenes using only odd numbers

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

const ll N = 1e6;

vector<bool> isprime(N+1,true);
void sieve()
{
    isprime[0] = isprime[1] = false;
    
    for(ll i=4;i<=N;i+=2)
    {
        isprime[i] = false;
    }
    
    for(ll i=3;i*i<=N;i+=2)
    {
        if(isprime[i])
        {
            for(ll j=i*i;j<=N;j+=2*i)
            {
                isprime[j] = false;
            }
        }
    }
} // TC : O(N log log N) , SC : O(N)

bool isPrime(ll n)
{
    if(n<=1)
        return false;
        
    if(!(n & 1))
        return n==2;
        
    for(ll i=3;i*i<=n;i+=2)
    {
        if(n % i == 0)
            return false;
    }
    return true;
} // TC : O(√n) (checks only odd divisors, about √n/2 iterations) , SC : O(1)

void solve()
{
    ll n;
    cin>>n;
    if(n <= 1e6)
        cout<<isprime[n];
    else
        cout<<isPrime(n);
} // TC : O(1) (precomputed) or O(√n) , SC : O(1)

int main()
{
    fastio();
    sieve();
    solve();
} // TC : O(N log log N + Query) , SC : O(N)
