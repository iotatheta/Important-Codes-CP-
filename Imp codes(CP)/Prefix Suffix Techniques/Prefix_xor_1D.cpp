// Prefix Xor 1D
// 1-based indexing
 
#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define ull unsigned long long
#define endl '\n'

vector<ll> pref_xor(const vector<ll> &arr)
{
    ll n = arr.size();
    vector<ll> pref(n + 1, 0);

    for(ll i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] ^ arr[i - 1];
    }

    return pref;

}
// TC: O(n)
// SC: O(n)

ll range_xor(const vector<ll> &pref, ll l, ll r)
{
    return pref[r] ^ pref[l - 1];

}
// TC: O(1)
// SC: O(1)

void solve()
{
    ll n;
    cin >> n;

    vector<ll> arr(n);

    for(ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    auto pref = pref_xor(arr);

    ll q;
    cin >> q;

    while(q-- > 0)
    {
        ll l, r;
        cin >> l >> r;

        cout << range_xor(pref, l, r) << endl;
    }

}
// TC: O(n + q)
// SC: O(n)

int main()
{
    fastio();
    solve();

}
// TC: O(n + q)
// SC: O(n)
