// Fibonacci Precompute with MOD (generally preferred) 

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define ll long long
#define endl '\n'

const ll N = 1e6; 
const ll MOD = 1e9+7; 
vector<ll> fib(N+1); 

void precompute()
{
    fib[0] = 0 , fib[1] = 1;
    for(int i=2;i<=N;i++)
    {
        fib[i] = (fib[i-1] + fib[i-2]) % MOD;
    }
}
// TC: O(N) 
// SC: O(N)

void solve()
{
    ll n;
    cin >> n;
    cout<< fib[n] << endl;
}
// TC: O(1)
// SC: O(1)

int main()
{
    fastio();
    precompute();
    ll t;
    cin >> t;
    while(t-- > 0)
    {
        solve();
    }
}
// TC: O(N + T)
// SC: O(N)
