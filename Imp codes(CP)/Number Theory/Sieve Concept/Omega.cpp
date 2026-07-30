// Number of Distinct Prime Factors
// omega[n] = Number of distinct prime factors of n
// omega[6] = 2 (2,3), omega[30] = 3 (2,3,5)

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

const ll N = 1e6;

vector<ll> omega(N+1,0);
void precompute()
{
    // i*i<=N skips last few element so will give wrong answer
    // use i*i<=N only for primality check
    // this is similiar to tou but the diff is it only counts number of distinct prime factors

    for(ll i=2;i<=N;i++) 
    {
        if(omega[i] == 0)
        {
            for(ll j=i;j<=N;j+=i)
            {
                omega[j]++;
            }
        }
    }
} // TC : O(N log log N) , SC : O(N) 

void solve()
{
    ll n;
    cin>>n;
    cout<<omega[n];
} // TC : O(1) , TC : O(1)

int main()
{
    fastio();
    precompute();
    solve();
}