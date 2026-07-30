// Sieve of Eratosthenes
// Prime Checking using Sieve and Trial Division

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

const ll N = 1e6;

vector<bool> isprime(N+1,true);
void sieve()
{
    isprime[0] = isprime[1] = false;
    for(ll i=2;i*i<=N;i++)
    {
        if(isprime[i])
        {
            for(ll j=i*i;j<=N;j+=i)
            {
                isprime[j] = false;
            }
        }
    }
} // TC : O(N log log N) , SC : O(N)

bool isPrime(ll n)
{
    if(n <= 1)
        return false;
        
    for(ll i=2;i*i<=n;i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
} // TC : O(√n) , SC : O(1)

void solve()
{
    ll n;
    cin>>n;
    if(n <= 1e6)
        cout<<isprime[n];
    else
        cout<<isPrime(n);
} // TC : O(1) (using sieve) or O(√n) , SC : O(1)

int main()
{
    fastio();
    sieve();
    solve();
} // TC : O(N log log N + Query) , SC : O(N)
