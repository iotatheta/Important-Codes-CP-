// function phi precompute
// Useful for leetcode

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define endl '\n'

vector<ll> precomputePhi(ll n)
{
    vector<ll> phi(n+1);
    for(ll i=0;i<=n;i++)
    {
        phi[i] = i;
    }
    for(ll i=2;i<=n;i++)
    {
        if(phi[i] == i)
        {
            for(ll j=i;j<=n;j+=i)
            {
                phi[j] = (phi[j] / i) * (i - 1);
            }
        }
    }
    return phi;
} // TC : O(n log log n) , SC : O(n)

void solve()
{
    ll n;
    cin>>n;
    auto phi = precomputePhi(n);
    
    for(ll i=0;i<=n;i++)
    {
        cout<<phi[i]<<" ";
    }
}
int main()
{
    fastio();
    solve();
}