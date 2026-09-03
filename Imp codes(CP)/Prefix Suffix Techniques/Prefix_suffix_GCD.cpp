// Range GCD query after excluding a given 1-based index range [l, r] using prefix and suffix GCD arrays.
/*

Eg - Input:
1
3 3
2 6 9
1 1
2 2
2 3

Output : 

3 
1 
2

*/

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define endl '\n'

vector<ll> prefix_GCD(const vector<ll>& arr)
{
    ll n = arr.size();
    vector<ll> pref(n+1, 0);
    
    for(ll i=1;i<=n;i++)
    {
        pref[i] = gcd(pref[i-1], arr[i-1]);
    }
    
    return pref;
}
// TC: O(N)
// SC: O(N)

vector<ll> suffix_GCD(const vector<ll>& arr)
{
    ll n = arr.size();
    vector<ll> suff(n+1, 0);
    
    for(ll i=n-1;i>=0;i--)
    {
        suff[i] = gcd(suff[i+1], arr[i]);
    }
    
    return suff;
}
// TC: O(N)
// SC: O(N)

ll range_GCD(const vector<ll>& pref, const vector<ll>& suff, const ll &l, const ll &r)
{
    return gcd(suff[r], pref[l-1]);
}
// TC: O(1)
// SC: O(1)

void solve()
{
    ll n, q;
    cin >> n >> q;
    
    vector<ll> arr(n);
    
    for(ll i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    
    auto pref = prefix_GCD(arr);
    auto suff = suffix_GCD(arr);
    
    ll l, r;
    
    while(q-- > 0)
    {
        cin >> l >> r;
        cout << range_GCD(pref, suff, l, r) << endl;
    }
}
// TC: O(N + Q)
// SC: O(N)

int main()
{
    fastio();
    
    int t;
    cin >> t;
    
    while(t-- > 0)
    {
        solve();
    }
}
// TC: O(T * (N + Q))
// SC: O(N)
