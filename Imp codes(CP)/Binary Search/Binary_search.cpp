// Binary Search [VVI.]
// O(log n) think whenever there is log n factor

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define endl '\n'

bool is_present(const vector<ll> &arr, ll x)
{
    ll low = 0, high = arr.size() - 1, mid;
    
    while(low <= high)
    {
        mid = low + ((high - low) >> 1ULL);
        
        if(arr[mid] == x)
            return true;
        else if(x > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    return false;
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
    
    while(k-- > 0)
    {
        cin >> x;
        
        if(is_present(arr, x))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
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
