// Euler Totient Using Totient
// I will only write the func for saving space but precomputation is highly recommended

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define endl '\n'

const ll N = 1e6;

vector<ll> spf(N+1);

void precompute()
{
    for(ll i=2;i<=N;i++)
    {
        if(spf[i] == 0) // Prime check
        {
            for(ll j=i;j<=N;j+=i)
            {
                if(spf[j] == 0)
                {
                    spf[j] = i;
                }
            }
        }
    }
}
// TC: O(N log log N)
// SC: O(N)

ll phi(ll n)
{
    ll res = n, p;
    
    while(n != 1)
    {
        p = spf[n];
        res = (res / p) * (p - 1);
        
        while(n % p == 0)
        {
            n /= p;
        }
    }
    
    return res;
}
// TC: O(log n)
// SC: O(1)

void solve()
{
    ll n;
    cin >> n;
    
    cout << phi(n);
}
// TC: O(log n)
// SC: O(1)

int main()
{
    fastio();
    precompute();
    
    solve();
}
// TC: O(N log log N + log n)
// SC: O(N)
