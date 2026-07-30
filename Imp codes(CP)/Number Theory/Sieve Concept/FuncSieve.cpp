// Sieve technique used in leetcode

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

vector<bool> sieve(ll n)
{
    vector<bool> isprime(n+1,true);
    if(n >= 0)
        isprime[0] = false;
    if(n >= 1)
        isprime[1] = false;
        
    for(int i=4;i<=n;i+=2)
    {
        isprime[i] = false;
    }
    for(int i=3;i*i<=n;i+=2)
    {
        if(isprime[i])
        {
            for(int j=i*i;j<=n;j+=2*i)
            {
                isprime[j] = false;
            }
        }
    }
    return isprime;
} // TC : O(n log log n) , SC : O(n)

void solve()
{
    ll n;
    cin>>n;
    auto isprime = sieve(n);
    for(ll i=2;i<=n;i++)
    {
        if(isprime[i])
            cout<<i<<" ";
    }
}

int main()
{
    fastio();
    solve();
}