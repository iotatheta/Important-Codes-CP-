// BPF (Biggest Prime Factor)

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define endl '\n'

const ll N = 1e6;

vector<ll> bpf(N+1,0);
void precompute()
{
    for(ll i=2;i<=N;i++)
    {
        if(bpf[i] == 0)
        {
            bpf[i] = i;
            for(ll j=2*i;j<=N;j+=i)
            {
                bpf[j] = i;
            }
        }
    }
} // TC : O(N log log N) , SC : O(N)

void solve()
{
    ll n;
    cin>>n;
    cout<<bpf[n];
} // TC : O(1) , SC : O(1)

int main()
{
    fastio();
    precompute();
    solve();
} // TC : O(N log log N) , SC : O(N)
