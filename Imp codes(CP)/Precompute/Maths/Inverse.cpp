/*
Euclidean Division:

 MOD = q * i + r ; (where,q = MOD / i, r = MOD % i)
    
    => r ≡ -q * i (mod MOD)
    
    Multiply by inv[r] and inv[i]:
    
    => inv[i] ≡ -q * inv[r] (mod MOD)
    
    Put the values of q and r:
    
    inv[i] = MOD - (MOD/i) * inv[MOD%i] % MOD
    
Since:
    MOD%i < i , we compute inverse values in increasing order.
*/

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define endl '\n'

#define i128 __int128

const ll N = 1e6;
const ll MOD = 1e9 + 7;

vector<ll> inv(N + 1);

void precomputeInverse()
{
    inv[1] = 1;

    for(ll i = 2; i <= N; i++)
    {
        inv[i] = MOD - (i128)(MOD / i) * inv[MOD % i] % MOD;
    }
}
// TC: O(N)
// SC: O(N)

void solve()
{
    ll n;
    cin >> n;

    cout << inv[n] << endl;
}
// TC: O(1)
// SC: O(1)

int main()
{
    fastio();
    precomputeInverse();

    int t;
    cin >> t;

    while(t-- > 0)
    {
        solve();
    }
}
// TC: O(N + T)
// SC: O(N)
