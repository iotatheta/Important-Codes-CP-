// Prefix sum is an array where each element at index i stores the sum of all elements from index 0 to i in the original array. It allows O(1) range sum queries.

// prefix[i] = prefix[i-1] + arr[i]
// range_sum(l,r) = prefix[r] - prefix[l-1] (if l>0) else prefix[r]

// ** 1-based indexing with l and r inclusive

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define ull unsigned long long
#define endl '\n'

#define i128 __int128

vector<ll> pref;

void prefix_sum(const vector<ll> &arr)
{
    ll n = arr.size();

    pref.resize(n + 1);

    pref[0] = 0;

    for(ll i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + arr[i - 1];
    }

}
// TC: O(n)
// SC: O(n)

ll rangeSum(const ll &l, const ll &r)
{
    if(l < 1 || l > r || r > (ll)pref.size() - 1)
        return 0;

    return pref[r] - pref[l - 1];

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

    prefix_sum(arr);

    ll q, l, r;
    cin >> q;

    while(q-- > 0)
    {
        cin >> l >> r;

        cout << rangeSum(l, r) << endl;
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
