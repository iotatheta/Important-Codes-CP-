// Lower bound = The smallest number that is >= x
// Applicable when the search space is sorted

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define endl '\n'

ll lower_bound_index(const vector<ll> &arr, const ll &x)
{
    ll low = 0, high = arr.size() - 1, mid, ans = -1;
    
    while(low <= high)
    {
        mid = low + ((high - low) >> 1ULL);
        
        if(arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    
    return ans;
}
// TC: O(log n)
// SC: O(1)

void solve()
{
    ll n, k, x;
    cin >> n >> k;
    
    vector<ll> arr(n);
    
    for(ll i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    
    ll ind;
    
    while(k-- > 0)
    {
        cin >> x;
        
        ind = lower_bound_index(arr, x);
        
        if(ind == -1)
            cout << "No lower bound" << endl;
        else
            cout << arr[ind] << endl;
    }
}
// TC: O(n + k log n)
// SC: O(n)

int main()
{
    fastio();
    solve();
}
// TC: O(n + k log n)
// SC: O(n)
