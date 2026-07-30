// tau(n)   -> Number of Divisors
// sigma(n) -> Sum of Divisors

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

const ll N = 1e6;

vector<ll> tou(N+1,0),sigma(N+1,0);
void precompute()
{
    for(ll i=1;i<=N;i++)
    {
        for(ll j=i;j<=N;j+=i)
        {
            tou[j]++;
        }
    }
    
    for(ll i=1;i<=N;i++)
    {
        for(ll j=i;j<=N;j+=i)
        {
            sigma[j] += i;
        }
    }
} // TC : O(N log N) , SC : O(N)

ll touFunc(ll n)
{
    if(n == 0)
        return 0;
        
    ll res = 1,cnt = 0;
    for(ll i=2;i*i<=n;i++)
    {
        cnt = 0;
        while(n % i == 0)
        {
            cnt++;
            n /= i;
        }
        res *= (cnt + 1);
    }
    if(n > 1)
        res *= 2;
        
    return res;
} // TC : O(√n) , SC : O(1)

ll power(ll a,ll b)
{
    if(b == 0)
        return 1;
        
    ll res = 1;
    while(b > 0)
    {
        if(b & 1)
            res = res * a;
        a = a * a;
        b = b >> 1;
    }
    return res;
} // TC : O(log b) , SC : O(1)

ll sigmaFunc(ll n)
{
    if(n <= 1)
        return n;
        
    ll res = 1,cnt = 0;
    for(ll i=2;i*i<=n;i++)
    {
        cnt = 0;
        while(n % i == 0)
        {
            cnt++;
            n /= i;
        }
        res *= (power(i,cnt+1) - 1) / (i - 1);
    }
    if(n > 1)
        res *= (1 + n);
        
    return res;
} // TC : O(√n) , SC : O(1)

void solve()
{
    ll n;
    cin>>n;
    if(n <= 1e6)
    {
        cout<<tou[n]<<" "<<sigma[n];
    }
    else
    {
        cout<<touFunc(n)<<" "<<sigmaFunc(n);
    }
} // TC : O(1) (precomputed) or O(√n) , SC : O(1)

int main()
{
    fastio();
    precompute();
    solve();
} // TC : O(N log N + Query) SC : O(N)
