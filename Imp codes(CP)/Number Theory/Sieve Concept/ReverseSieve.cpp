// Reverse sieve (Frequency Sieve)
// Use of frequency concept in sieve

#include <bits/stdc++.h>
using namespace std;
 
#define fastio() ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
 
const ll N = 1e6; // use N = 1e7 for high values of primality check

vector<ll> freq(N+1,0);
void solve()
{
    ll n,maxi = INT_MIN;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        freq[arr[i]]++;
        maxi = max(maxi,arr[i]);
    }
    ll cnt=0;
    for(ll i=maxi;i>=1;i--)
    {
        cnt=0;
        for(ll j=i;j<=maxi;j+=i)
        {
            cnt += freq[j];
            if(cnt >= 2)
            {
                cout<<i;
                return;
            }
        }
    } // TC : O(M log M), where M = max(arr) , SC : O(1)
}

int main()
{
    fastio();
    solve();
}
