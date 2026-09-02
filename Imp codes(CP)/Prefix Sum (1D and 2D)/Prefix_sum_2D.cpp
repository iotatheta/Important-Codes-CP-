// Prefix Sum in 2D matrix of n x n
// 1 - based indexing

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define ull unsigned long long
#define endl '\n'

vector<vector<ll>> prefix_sum_2D(const vector<vector<ll>> &arr)
{
    ll n = arr.size();

    vector<vector<ll>> pref(n + 1, vector<ll>(n + 1, 0));

    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 1; j <= n; j++)
        {
            pref[i][j] = pref[i - 1][j]
                       + pref[i][j - 1]
                       - pref[i - 1][j - 1]
                       + arr[i - 1][j - 1];
        }
    }

    return pref;
}
// TC: O(n^2)
// SC: O(n^2)

ll range_sum(const vector<vector<ll>> &pref,
             ll l1, ll l2, ll r1, ll r2)
{
    return pref[r1][r2]
         - pref[l1 - 1][r2]
         - pref[r1][l2 - 1]
         + pref[l1 - 1][l2 - 1];

}
// TC: O(1)
// SC: O(1)

void solve()
{
    ll n;
    cin >> n;

    vector<vector<ll>> arr(n, vector<ll>(n));

    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    auto pref = prefix_sum_2D(arr);

    ll q;
    cin >> q;

    while(q-- > 0)
    {
        ll l1, l2, r1, r2;
        cin >> l1 >> l2 >> r1 >> r2;

        cout << range_sum(pref, l1, l2, r1, r2) << endl;
    }

}
// TC: O(n^2 + q)
// SC: O(n^2)

int main()
{
    fastio();
    solve();

}
// TC: O(n^2 + q)
// SC: O(n^2)
