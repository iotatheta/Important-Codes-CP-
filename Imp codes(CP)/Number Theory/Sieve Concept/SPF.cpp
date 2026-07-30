// Smallest Prime Factor (SPF)
// Prime Factorization using SPF

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

const ll N = 1e6;

vector<ll> spf(N+1,0); 
void precompute()
{
    spf[0] = spf[1] = 0;
    for(ll i=2;i<=N;i++)
    {
        if(spf[i] == 0)
        {
            spf[i] = i;
            for(ll j = i*i;j<=N;j+=i)
            {
                if(spf[j] == 0)
                    spf[j] = i;
            }
        }
    }
} // TC : O(N log log N) , SC : O(N)

vector<ll> primeFactorsSPF(ll n)
{
    vector<ll> res;
    while(spf[n] != 0)
    {
        res.push_back(spf[n]);
        n /= spf[n];
    }
    if(n > 1)
        res.push_back(n);
        
    return res;
} // TC : O(log n) , SC : O(log n)

vector<ll> primeFactorsTrial(ll n)
{
    vector<ll> res;
    for(ll i=2;i*i<=n;i++)
    {
        while(n % i == 0)
        {
            res.push_back(i);
            n /= i;
        }
    }
    if(n > 1)
        res.push_back(n);
    
    return res;
} // TC : O(√n) , SC : O(log n)

void solve()
{
    ll n;
    cin>>n;
    vector<ll> res;
    if(n <= 1e6)
        res = primeFactorsSPF(n);
    else
        res = primeFactorsTrial(n);
        
    for(ll i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
} // TC : O(log n) (SPF) or O(√n) , SC : (Trial) O(log n)

int main()
{
    fastio();
    precompute();
    solve();
} // TC : O(N log log N + Query) , SC : O(N)
