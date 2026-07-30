// Sum of all ϕ(n)^2 in a range
// Use unsigned long long (upto 18 * 1e18) and long long( 9 * 1e18 )

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll unsigned long long
#define endl '\n'

const int N = 5 * 1e6;
vector<int> phi(N+1);
vector<ll> sum(N+1,0);
void precompute()
{
    for(int i=0;i<=N;i++)
    {
        phi[i] = i;
    }
    for(int i=2;i<=N;i++)
    {
        if(phi[i] == i)
        {
            for(ll j=i;j<=N;j+=i)
            {
                phi[j] = (phi[j] / i) * (i - 1);
            }
        }
    }
    
    for(int i=1;i<=N;i++)
    {
        sum[i] = sum[i-1] + (1ULL * phi[i] * phi[i]);
        // use 1ULL and int * int will overflow
    }
} // TC: O(N log log N) , SC: O(N)

void solve(int i)
{
    int a,b;
    cin>>a>>b;
    ll ans = sum[b] - sum[a-1];
    cout<< "Case " << i << ": " << ans << endl;
}

int main()
{
    fastio();
    precompute();
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        solve(i);
    }
}